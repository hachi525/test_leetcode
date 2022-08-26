//
// Created by admin on 2022/7/23.
//

#include "O115_sequenceReconstruction.h"

/* 拓扑排序 */
bool O115_sequenceReconstruction::sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences) {
    int n = nums.size();
    vector<int> inDegree(n+1, 0);
    vector<unordered_set<int>> graph(n+1);
    for (vector<int>& sequence:sequences) {
        for (int i = 1; i < sequence.size(); ++i) {
            int prev = sequence[i-1], next = sequence[i];
            if (!graph[prev].count(next)) {
                graph[prev].emplace(next);
                inDegree[next]++;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0)
            q.emplace(i);
    }// 入度为0的入队
    while(!q.empty()){
        if (q.size()>1)
            return false;
        int num = q.front();
        q.pop();
        for (int next:graph[num]) {
            inDegree[next]--;
            if (inDegree[next] == 0)
                q.emplace(next);
        }
    }
    return true;
}

/* 暴力 */
bool O115_sequenceReconstruction::sequenceReconstruction1(vector<int> &nums, vector<vector<int>> &sequences) {
    int n = nums.size();
    vector<int> pre(n+1);
    for (int i = 1; i < n; ++i) {
        pre[nums[i]] = nums[i-1];
    }

    vector<bool> visited(n+1);
    for (auto& sequence:sequences) {
        for (int i = 1; i < sequence.size(); ++i) {
            if (!visited[sequence[i]] && pre[sequence[i]] == sequence[i-1])
                visited[sequence[i]] = 1;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (!visited[nums[i]])
            return false;
    }
    return true;
}

void Test(){
    vector<int> nums;
    vector<vector<int>> sequences;
    O115_sequenceReconstruction solution;
    cout << boolalpha <<  solution.sequenceReconstruction(nums, sequences) << endl;
}

int main() {

    return 0;
}
