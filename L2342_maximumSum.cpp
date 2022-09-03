//
// Created by admin on 2022/9/3.
//
#include <unordered_map>
#include <vector>

#include <iostream>

using namespace std;

class Solution{
public:
    int getSum(int num){
        int sum = 0;
        for(int i = num; i ; i/= 10){
            sum += i%10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums){
        unordered_map<int, int> map;
        int res = 0;
        for(auto& num : nums){
            int sum = getSum(num);  //num的数位和
            if(map.count(sum)){
                res = max(num + map[sum], res);
            }
            map[sum] = max(num, map[sum]);
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int > nums = {18, 43, 36, 13, 7};
    solution->maximumSum(nums);
    return 0;
}
