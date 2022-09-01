//
// Created by admin on 2022/9/1.
//
#include <iostream>

using namespace std;

class Solution{
public:
    int premiageSizeFZF(int k){
        long start = 0L, end = 5L*k, mid;
        while(start < mid){
            mid = start + (end-start)/2;
            long n = 5L,nums = 0L;
            while(n <= mid){
                nums += mid/n;
                n *= 5;
            }

            if(nums == k)
                return 5;
            if(nums < k)
                start = mid + 1;
            else
                end = mid -1;
        }
        return 0;
    }
};
