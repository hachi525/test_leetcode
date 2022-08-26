//
// Created by admin on 2022/7/23.
//

#ifndef PROJECT_HASCIRCLE_H
#define PROJECT_HASCIRCLE_H
#ifndef _hasCircle_H_
#define _hasCircle_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "graph_adjList.h"

using namespace std;

class hasCircle {
private:
    vector<bool> visited;
    vector<bool> onPath;
    bool hasCircle;
public:
    // 从节点 s 开始 DFS 遍历，将遍历过的节点标记为 true
    void traverse(Graph graph, int s);
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
};


#endif //_hasCircle_H_
#endif //PROJECT_HASCIRCLE_H
