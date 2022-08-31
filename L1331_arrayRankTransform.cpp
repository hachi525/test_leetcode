//
// Created by admin on 2022/7/28.
//

#include "L1331_arrayRankTransform.h"

vector<int> L1331_arrayRankTransform::arrayRankTransform(vector<int> &arr) {
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    vector<int> res(arr.size());
    for (int& num:temp) {
        if (!map.count(num)){
            map[num] = map.size()+1;
        }
    }
    for (int i = 0; i < arr.size(); ++i) {
        res[i] = map[arr[i]];
    }
    return res;
}

class Solution{
public:
    vector<int> arrayRankTransform(vector<int>& arr){
        int n  = arr.size();
        for(int i = 0; i < n; i ++){
            int j = i < n ? 2 * i : 2 * (i-n) + 1;
            arr[j] |= (arr[i] & 1023) << 10 ;
        }
        for(auto& e : arr){
            e = e >> 10;
        }
        return arr;
    }
};

void discretization(vector<int>& nums){
    sort(nums.begin()+1, nums.begin()+1+nums.size());



}

int main() {

    return 0;
}
