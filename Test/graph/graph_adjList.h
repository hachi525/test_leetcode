//
// Created by admin on 2022/7/23.
//

#ifndef PROJECT_GRAPH_ADJLIST_H
#define PROJECT_GRAPH_ADJLIST_H

#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<bool> onPath;

struct ArcNode{
    int adjVex;     //邻居节点
    int weight;     //权重
    ArcNode* next;  //下一条边
};

struct VexNode{
    int vex;
    ArcNode* first;
};

struct Graph{
    int vexNum;
    int arcNum;
    int type;   //图的种类-有向图无向图
//    vector<VexNode*> adjList;   // 邻接表
    vector<vector<int>> adjList;    //邻接表
};

Graph buildGraph(vector<vector<int>> vex){

}

/* 图遍历框架-DFS */
void traverse(Graph graph, int s) {
    if (visited[s]) return;
    // 经过节点 s，标记为已遍历
    visited[s] = true;
    // 做选择：标记节点 s 在路径上
    onPath[s] = true;
    for (int neighbor : graph.adjList[s]) {
        traverse(graph, neighbor);
    }
    // 撤销选择：节点 s 离开路径
    onPath[s] = false;
}

#endif //PROJECT_GRAPH_ADJLIST_H
