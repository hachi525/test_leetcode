//
// Created by admin on 2022/8/26.
//
#include<vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while(k --){
            if(left < 0){
                right ++;
            }else if(right >= arr.size()){
                left --;
            }else if(x-arr[left] <= arr[right]-x){
                left --;
            }else {
                right ++;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};


int main (){
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5};
    solution.findClosestElements(arr, 2, 4);
}