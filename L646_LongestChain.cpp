//
// Created by admin on 2022/9/3.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findLongestChain(vector<vector<int> >& pairs) {
        /* 动态规划 */
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        // dp[i]：以pairs[i]为结尾的最长数对长度
        // 状态转移方程：dp[i] = max(dp[i], );
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];

        /* 二分+贪心 */


        /* 贪心 */
        // 按照第二个数从小到大排列
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int res = 0, curr = INT_MIN;
        for(auto& pair:pairs){
            if(curr < pair[0]){
                curr = pair[1];
                curr ++;
            }
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int> > pairs;
    solution->findLongestChain(pairs);

    return 0;
}
