//
// Created by admin on 2022/7/20.
//

#ifndef PROJECT_L1439_KTHSMALLESTSUM_H
#define PROJECT_L1439_KTHSMALLESTSUM_H
#ifndef _L1439_kthSmallestSum_H_
#define _L1439_kthSmallestSum_H_


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class L1439_kthSmallestSum {
private:
    int cnt = 0, K;
public:
    int kthSmallest(vector<vector<int>>& mat, int k);
    void dfs(vector<vector<int>> &mat, int row, int sum, int target, int k);
};


#endif //_L1439_kthSmallestSum_H_
#endif //PROJECT_L1439_KTHSMALLESTSUM_H
