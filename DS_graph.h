//
// Created by admin on 2022/9/8.
//

#ifndef PROJECT_DS_GRAPH_H
#define PROJECT_DS_GRAPH_H
#define inf 0x7ffffff
#define max 0x3f3f3f3f

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;   // 顶点数量

// 边集数组
struct Edge{
    int to, next, w;
}edge[N];

// 头节点数组 head[i]存储以i为起点的第一条边的下标(在e[]中的下标)
int head[N];
int cnt;

void init() {
    for(int i = 0; i <= 5; ++i)
        head[i] = -1;  // head初始都为-1
    cnt = 0;
};

/* 加边 */
void add_Edge(int u, int v, int w){
    edge[cnt].to = v;           // 弧头节点
    edge[cnt].next = head[u];   // 指向上一条边
    edge[cnt].w = w;
    head[u] = cnt ++;
}

void traverse(){
    for(int i = 1; i <= N; i ++){ //i为顶点的值，head[i]存的是第一条边的
        for (int j = head[i]; ~j; j = edge[j].next) {   //j为结点i的边在边数组edge中的下标
            cout << "start = " << i << ", end = " << edge[j].to << ", weight = " << edge[j].w << endl;
        }
    }
}


int h[N], ne[2*N], e[2*N], w[2*N];
int idx = 0;
void Init(){
    memset(h, -1, sizeof(h));
}

void add (int u, int v, int weight){
    e[idx] = v;     // 弧头节点v
    w[idx] = weight;// 边的权值w
    ne[idx] = h[u]; // 新的边指向，
    h[u] = idx++;   // 顶点u的第一条边在边数组中的下标更新
}

void traverse1(){
    for(int i = 1; i <= N; i ++){
        for (int j = h[i]; ~j; j = ne[j]) {
            cout << "start = " << i << ", end = "<< e[j] << ", weight = " << w[j] <<endl;
        }
    }
}


void dijkstra(int s){

}


#endif //PROJECT_DS_GRAPH_H
