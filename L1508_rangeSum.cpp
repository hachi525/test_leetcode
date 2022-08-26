//
// Created by admin on 2022/7/9.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution{
public:
/*  //多路归并+优先级队列思路，可以解决，其实相当于是多路前缀和
    struct cmp{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.first > b.first;
        }
    };
    int rangeSum(vector<int>& nums, int n, int left, int right){
        int mod = 1e9+7;
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});//头节点包含两个值：子数组和，子数组的右边界
        }
        int ans = 0;

        for (int i = 1; i <= right; ++i) {
            int sum = pq.top().first, j = pq.top().second;
            pq.pop();
            if(i >= left)   ans = (ans + sum)%mod;// 开始记录结果
            if(j+1 < n)     pq.push({sum+nums[j+1], j+1});
            // 如果 j + 1 < n 表示该条链条后面还有元素，可以继续加入队列中
        }
        return ans;
    }
*/
    /* 暴力求解 */
    int rangeSum(vector<int>& nums, int n, int left, int right){
        /* 使用前缀和，暴力求出所有子数组的和，然后sort排序后输出对应区间和的和 */
        int MOD = 1e9+7;
        int res = 0;
        vector<int> preSum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            preSum[i+1] = preSum[i] + nums[i];
        }

        vector<int> a;//或者这里就不用vector，而是用优先队列，不用再使用sort进行排序
        /* 暴力求出所有非空连续子数组的和 */
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                a.push_back(preSum[j+1] - preSum[i]);  //preSum[j+1]-preSum[i]为下标[i, j]区间和
            }
        }
        sort(a.begin(), a.end());
        for (int i = left-1; i < right; ++i) {
            res = (res + a[i]) % MOD;
        }
        return res;
    }

    /* 二分优化暴力求解，前缀和数组+前缀和的前缀和数组 */
    int rangeSum1(vector<int>& nums, int n, int left, int right){

    }

};

int main(){
    int n, left, right;
    cin >> n >> left >> right ;
    vector<int> nums(4);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << nums[2] << endl;

    Solution solution;
    cout << solution.rangeSum(nums, n, left, right) ;
    cout << solution.rangeSum1(nums, n, left, right) ;
    return 0;
}
