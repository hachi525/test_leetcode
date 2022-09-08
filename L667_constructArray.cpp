//
// Created by admin on 2022/9/8.
//
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

class Solution{
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;

        for(int i = 1; i < n-k; i ++)   res.push_back(i);

        for(int i = n-k, j = n; i <= j; i ++, --j){
            res.push_back(i);
            if(i != j)  res.push_back(j);
        }
        return res;
    }
};


int main(){
    int n, k;
    cin >> n >> k;

    Solution solution;
    solution.constructArray(n, k);
    return 0;
}