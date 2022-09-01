//
// Created by admin on 2022/9/1.
//
#include <vector>
#include <stack>

using namespace std;

class Solution{
public:
    vector<int> finalPrice(vector<int> &prices){
        /* 暴力解法,原地修改 */
//        int n = prices.size();
//        for(int i = 0; i < n; i ++){
//            for(int j = i+1; j < n; j ++){
//                if(prices[j] <= prices[i]){
//                    prices[i] -= prices[j];
//                    break;
//                }
//            }
//        }
//        return prices;

        /* 单调栈解法 */
        int n = prices.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = n-1; i >=0; --i) {
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }
            res[i] = st.empty()? prices[i] : prices[i] - st.top();
            st.emplace(prices[i]);
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> prices;

    solution.finalPrice(prices);
    return 0;
}
