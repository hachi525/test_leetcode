//
// Created by admin on 2022/7/20.
//

#include "L1439_kthSmallestSum.h"

/* 给你一个 m * n 的矩阵 mat，以及一个整数k，矩阵中的每一行都以非递减的顺序排列
 * 你可以从每一行中选出1个元素形成一个数组。
 * 返回：所有可能数组中的第k个最小数组和
 * */
int L1439_kthSmallestSum::kthSmallest(vector<vector<int>> &mat, int k) {
    int m = mat.size(), n = mat[0].size();
    int left = 0, right = 1;
    for (int i = 0; i < m; i++) {
        left += mat[i][0];
        right += mat[i][n - 1];
    }
    int minSum = left;
    while (left < right){
        int mid = left + (right-left)/2;
        cnt = 1;
        dfs(mat, 0, minSum, mid, k);
        if(cnt >= k)
            right = mid;
        else
            left = mid+1;
    }
    return left;
}

/* DFS递归第row行找数组和小于等于target的数量 */
void L1439_kthSmallestSum::dfs(vector<vector<int>> &mat, int row, int sum, int target, int k) {
    int m = mat.size(), n = mat[0].size();
    if (sum > target || cnt > K || row >= m)
        return;
    dfs(mat, row+1, sum, target, k);//不换列，换行

    for (int i = 1; i < n; ++i) {//换列，不换行
        int curSum = sum - mat[row][0] + mat[row][i];
        if (curSum > target) break;
        cnt ++;
        dfs(mat, row+1, curSum, target, k);
    }
}

int main() {

    return 0;
}
