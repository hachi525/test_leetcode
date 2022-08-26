//
// Created by admin on 2022/7/23.
//

#ifndef PROJECT_TOPOSORT_H
#define PROJECT_TOPOSORT_H
#ifndef _TopoSort_H_
#define _TopoSort_H_


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "graph_adjList.h"

using namespace std;

class TopoSort {
private:
    bool hasCircle = false;
public:
    vector<int> topoSort(Graph graph, vector<int>& inDegree);
};


#endif //_TopoSort_H_
#endif //PROJECT_TOPOSORT_H
