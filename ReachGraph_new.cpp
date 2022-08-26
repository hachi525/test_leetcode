//
// Created by admin on 2022/7/15.
//
//
// Created by admin on 2022/7/15.
//
#include <stdio.h>
#include "tinyxml.h"
#include <iostream>
#include <cstring>
#include<string>
#include<vector>
#include <stdlib.h>
#include<fstream>
using namespace std;

struct Arc {
    string id;
    string source;
    string target;
    int sourceNum = 0;
    int sourceP = 0;//源节点是库所，则sourceP为1
    int sourceT = 0;
    int targetNum = 0;
};

//库所顶点表
typedef struct Place
{
    string name;
    int num = 0;
    int initialMarking = 0;
};

//变迁顶点表
typedef struct Transition
{
    string name;
    int num = 0;
};
int m = 0;
int n = 0;
int arcnum = 0;
Place place[30];
Transition transition[30];
Arc arc[1000];
int A[30][30] = { 0 };//关联矩阵
int A1[30][30] = { 0 };//输出矩阵
int A2[30][30] = { 0 };//输入矩阵

//可达图节点
typedef struct Node {
    int m[30] = { 0 };//标识
    int flag = 0;//新0，旧1，端点2
    int isfirable[30] = { 0 };//存储可以发生的变迁名字
    struct Node *parent;//该节点的父节点
    int t = 0;//存储生成这个节点所发生的变迁名字
};

void readPNML() {
    TiXmlDocument mydoc("E:\\1model.pnml");
    bool loadOK = mydoc.LoadFile();
    if (!loadOK) {
        cout << "could not load the test file" << endl;
        exit(1);
    }
    TiXmlElement *pnmlElement = mydoc.RootElement();
    TiXmlElement *netElement = pnmlElement->FirstChildElement();
    TiXmlElement *pageElement = netElement->FirstChildElement("page");
    for (TiXmlElement *petriElement = pageElement->FirstChildElement();//第一个子元素
         petriElement;
         petriElement = petriElement->NextSiblingElement())
    {
        if (petriElement->ValueTStr() == "place") {
            place[m].num = m;
            if (petriElement->FirstChildElement("initialMarking")) {
                TiXmlElement *initialMarkingElement = petriElement->FirstChildElement("initialMarking")->FirstChildElement("text");
                place[m].initialMarking = atoi(initialMarkingElement->GetText());
            }
            TiXmlElement *nameElement = petriElement->FirstChildElement("name")->FirstChildElement("text");
            place[m].name = nameElement->GetText();
            m++;
        }
        if (petriElement->ValueTStr() == "transition") {
            transition[n].num = n;
            TiXmlElement *tnameElement = petriElement->FirstChildElement("name")->FirstChildElement("text");
            transition[n].name = tnameElement->GetText();
            n++;
        }
        if (petriElement->ValueTStr() == "arc") {
            TiXmlAttribute *arcAttr = petriElement->FirstAttribute();
            arc[arcnum].id = arcAttr->Value();
            arcAttr = arcAttr->Next();
            arc[arcnum].source = arcAttr->Value();
            arcAttr = arcAttr->Next();
            arc[arcnum].target = arcAttr->Value();
            arcnum++;
        }
    }
    for (int i = 0; i < arcnum; i++) {//对于每一条弧
        for (int j = 0; j < n; j++) {//和变迁比
            if (arc[i].source.compare(transition[j].name) == 0) {
                arc[i].sourceT = 1;
                arc[i].sourceNum = transition[j].num;
            }
            if (arc[i].target.compare(transition[j].name) == 0) {
                arc[i].targetNum = j;
            }
        }
        for (int k = 0; k < m; k++) {//和库所比
            if (arc[i].source.compare(place[k].name) == 0) {
                arc[i].sourceP = 1;
                arc[i].sourceNum = place[k].num;
            }
            if (arc[i].target.compare(place[k].name) == 0) {
                arc[i].targetNum = k;
            }
        }
    }
}

void getA() {
    for (int i = 0; i < arcnum; i++) {
        if (arc[i].sourceP == 1) {
            A[arc[i].targetNum][arc[i].sourceNum]--;
            A2[arc[i].targetNum][arc[i].sourceNum]++;//输入矩阵
        }

        if (arc[i].sourceT == 1) {
            A[arc[i].sourceNum][arc[i].targetNum]++;
            A1[arc[i].sourceNum][arc[i].targetNum]++;//输出矩阵
        }
    }
}

void printA() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }
}

void printA1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A1[i][j] << "  ";
        }
        cout << endl;
    }
}

void printA2() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A2[i][j] << "  ";
        }
        cout << endl;
    }
}

//可达图中的边表
typedef struct RGEdge {
    int t;//有向边代表的发生的变迁编号
    int target;//该有向边目标节点的状态编号
    struct RGEdge *nextedge = NULL;//该边指向的下一条边
}RGEdge, *PRGEdge;

//可达图中的顶点表
typedef struct RGNode {
    int m[100];//该状态存储的标识信息
    int flag = 0;//新0，旧1
    int isfirable[100] = { 0 };//从该标识出发可以发生的变迁名字
    int enableNum = 0;//该标识可以发生的变迁数目
    int t = 0;//存储生成这个节点所发生的变迁名字
    PRGEdge firstEdge;
}RGNode, *PRGNode;

//可达图
typedef struct RG {
    int node = 0;
    int edge = 0;
    RGNode rgnode[300];//假设有300个标识
}RG, *PRG;

int M0[100] = { 0 };
int M1[100] = { 0 };
int M[100] = { 0 };
void ReachabilityTree() {
    RG graph;
    //新建一个可达图，初始状态，可达图中节点个数为0
    graph.node = 0;
    //可达图的第一个节点（一个节点：初始标识）
    for (int i = 0; i < m; i++) {
        M0[i] = place[i].initialMarking;
        graph.rgnode[0].m[i] = M0[i];
    }
    graph.node++;
    //判断结点列表中还存在没有标记的节点
    int newNode;
    int exist;
    while (1) {
        for (int i = 0; i < graph.node; i++) {
            exist = 0;
            if (graph.rgnode[i].flag == 0) {//找到标识为新的节点
                exist = 1;
                newNode = i;
                break;
            }
        }
        if (exist != 1) {//不存在标识为新的节点
            break;
        }
        //任选标识为新的节点newNode，设为M
        for (int i = 0; i < m; i++) {
            M[i] = graph.rgnode[newNode].m[i];
        }
        //标记这个节点
        graph.rgnode[newNode].flag = 1;

        //if 在M下所有变迁都不能发生
        int enable;
        int enableNumber = 0;
        for (int i = 0; i < n; i++) {//对于所有的变迁
            enable = -1;
            for (int j = 0; j < m; j++) {
                if (M[j] < A2[i][j]) {//变迁ti不能发生
                    enable = 0;
                    break;
                }
            }
            //变迁从t0开始编号
            if (enable == -1) {//变迁ti可以发生
                graph.rgnode[newNode].isfirable[enableNumber] = i;
                graph.rgnode[newNode].enableNum++;
                enableNumber++;
            }
        }
        if (graph.rgnode[newNode].enableNum == 0) {//如果变迁不能发生则跳出本次循环
            continue;
        }
        //对于每个在M下可发生的变迁
        for (int i = 0; i < graph.rgnode[newNode].enableNum; i++) {
            //可发生变迁ti的编号i为hang
            //计算M1
            for (int j = 0; j < m; j++) {
                int hang = graph.rgnode[newNode].isfirable[i];
                M1[j] = M[j] + A[hang][j];
            }
            //if结点列表中出现过M1
            int repeated;
            int ii;
            int exist = 0;
            for (ii = 0; ii < graph.node; ii++) {
                repeated = 1;
                for (int jj = 0; jj < m; jj++) {
                    if (M1[jj] != graph.rgnode[ii].m[jj]) {
                        repeated = 0;
                        break;
                    }
                }
                //若结点列表出现过M1
                if (repeated == 1) {
                    exist = 1;
                    //ii是重复的节点的序号
                    PRGEdge pEdge;
                    pEdge = new RGEdge;
                    pEdge->nextedge = NULL;
                    pEdge->t = graph.rgnode[newNode].isfirable[i];
                    pEdge->target = ii;
                    RGNode *p;
                    p = &graph.rgnode[newNode];
                    pEdge->nextedge = p->firstEdge;
                    p->firstEdge = pEdge;
                    break;
                }
            }
            //若M1是没有出现过的新状态
            if (exist == 0) {
                //则引入新节点rgnode[graph.node]，即M1。
                for (int i = 0; i < m; i++) {
                    graph.rgnode[graph.node].m[i] = M1[i];
                }
                graph.rgnode[graph.node].flag = 0;
                graph.rgnode[graph.node].t = graph.rgnode[newNode].isfirable[i];
                //并把新节点加到邻接表边表上
                //bug这部分的连接有问题
                RGNode *p;
                PRGEdge pEdge;
                pEdge = new RGEdge;
                pEdge->nextedge = NULL;
                pEdge->t = graph.rgnode[newNode].isfirable[i];
                pEdge->target = graph.node;
                p = &graph.rgnode[newNode];
                pEdge->nextedge = p->firstEdge;
                p->firstEdge = pEdge;
                graph.node++;
            }
        }
    }
    //打印可达图
    cout << "可达图节点个数" << graph.node << endl;
    for (int i = 0; i < graph.node; i++) {
        cout << "M[" << i << "]" << "(";
        for (int j = 0; j < m; j++) {
            cout << graph.rgnode[i].m[j] << " ";
        }
        cout << ")";
        PRGEdge p;
        p = graph.rgnode[i].firstEdge;
        for (int k = 0; k < graph.rgnode[i].enableNum; k++) {
            cout << "[t";
            cout << p->t;
            cout << "M";
            cout << p->target;
            cout << ",";
            p = p->nextedge;
        }
        cout << endl;
    }
}


int main() {
    readPNML();//读取pnml文档信息
    getA();//生成关联矩阵
    printA();//打印关联矩阵
//	printA1();//打印输出矩阵
//	printA2();//打印输入矩阵

    ReachabilityTree();//生成可达树
//	cout << "生成的可达树为" << endl;
    //	PrintReachabilityTree();//打印可达树
    system("pause");
    return 0;
}