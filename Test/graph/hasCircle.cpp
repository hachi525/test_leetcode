//
// Created by admin on 2022/7/23.
//

#include "hasCircle.h"

/* L207 课程表 判断课程链是否成环，是则false */
bool hasCircle::canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    visited.resize(numCourses);
    onPath.resize(numCourses);
    Graph graph = buildGraph(prerequisites);
    for (int i = 0; i < numCourses; ++i) {
        hasCircle::traverse(graph, i);
    }
    return !hasCircle;
}

/* DFS遍历 */
void hasCircle::traverse(Graph graph, int s) {
    if (onPath[s])  hasCircle = true;
    if (visited[s] || hasCircle) return ;
    visited[s] = true;
    onPath[s] = true;
    for (int t:graph.adjList[s]) {
        traverse(graph, t);
    }
    onPath[s] = false;
}

int main() {

    return 0;
}
