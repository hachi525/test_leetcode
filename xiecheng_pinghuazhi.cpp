//
// Created by admin on 2022/8/30.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution{
public:
    int pinghuazhi(vector<int>& nums){
        pair<int, int> maxDif = {nums[1] - nums[0], 1};
        pair<int, int> secMaxDif = maxDif;
        vector<int> temp(nums.size());
        // 差分数组
        for(int i = 1; i < nums.size(); i ++) {
            temp[i] = nums[i] - nums[i - 1];
            if(maxDif.first < temp[i]){
                secMaxDif = maxDif;
                maxDif.first = temp[i];
                maxDif.second = i;
            }
        }
        // 如果最大差和次大差的下标相连
        if(abs(maxDif.second - secMaxDif.second) <= 1){
            int diff = (maxDif.first + secMaxDif.first)%2 == 0 ?
                    (maxDif.first + secMaxDif.first)/2 :
                    (maxDif.first + secMaxDif.first)/2 +1 ;
            int cmpDif = 0;
            if(maxDif.second == 1 || secMaxDif.second == 1){
                cmpDif = maxDif.second == 1 ? temp[secMaxDif.second + 1] : temp[maxDif.second + 1];
            }else if(maxDif.second == nums.size()-1 || secMaxDif.second == nums.size()-1){
                cmpDif = secMaxDif.second == nums.size()-1 ? temp[maxDif.second - 1] : temp[secMaxDif.second - 1];
            }else{
                cmpDif = maxDif.second > secMaxDif.second ?
                             max(temp[maxDif.second + 1], temp[secMaxDif.second - 1]) :
                             max(temp[maxDif.second - 1], temp[secMaxDif.second + 1]);
            }
            return max(diff, cmpDif);
        }else{
            int cmpDif = max(temp[maxDif.second - 1], temp[maxDif.second + 1]);
            return max(secMaxDif.first, cmpDif);
        }
    }
};

int main (){
    Solution solution;
    vector<int> nums = {-1, 1, 2, 5, 11};
    cout << solution.pinghuazhi(nums) << endl;
    return 0;
}

