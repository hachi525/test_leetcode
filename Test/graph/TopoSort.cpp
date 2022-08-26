//
// Created by admin on 2022/7/23.
// 写的是个shit

#include "TopoSort.h"
/* 拓扑排序步骤：广度优先搜索思路
 * （1）定义一个队列Q，并把所有入度为0的结点加入队列
 * （2）取队首结点，访问输出，然后删除所有从它出发的边，并令这些边到达的顶点的入度减1，如果某个顶点的入度减为0，则将其加入队列。
 * （3）重复进行（2）操作，直到队列为空。如果队列为空时入过队的结点数恰好为N，说明拓扑排序成功，图G为有向无环图；否则，拓扑排序失败，图G有环。
 */
vector<int> TopoSort::topoSort(Graph graph, vector<int>& inDegree) {
    queue<int> que;
    int num = 0;
    for (int i = 0; i < graph.vexNum; ++i) {
        if (inDegree[i] == 0)   que.push(i);
    }
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for (int i = 0; i < graph.adjList[u].size(); ++i) {
            int v = graph.adjList[u].next;
            inDegree[v] --;
            if (inDegree[v] == 0)   que.push(v);
        }
        // 清除顶点u的所有出边

        num++;
    }
    if (num == graph.vexNum)
        return 1;//
}

int main() {

    return 0;
}
