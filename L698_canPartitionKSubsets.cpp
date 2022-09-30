//
// Created by admin on 2022/9/20.
//


#include <bits/stdc++.h>

using namespace std;

class Solution{
    // 以数字的视角
    bool dfs(vector<int>& nums, vector<int> &bucket, int cur, int target){
        if(cur == nums.size()){
//            for(int i = 0; i < bucket.size(); i++){
//                if (bucket[i]!= target){
//                    return false;
//                }
//            }
            return true;
        }

        for(int i = 0; i < bucket.size(); i ++){
            if(bucket[i] + nums[cur] > target)  continue;
            bucket[i] += nums[cur];
            if(dfs(nums, bucket, cur + 1, target))  return true;
            bucket[i] -= nums[cur];
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k){
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % k > 0)   return false;
        int per = total / k, n = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b)->bool{return a>b;});
        vector<int> bucket(k);
        return dfs(nums, bucket, 0, per);
    }

    // 以桶的视角
    bool backtrack(int k, int bucket, vector<int>& nums, int start, bool vis[], int target){
        if (k == 0) return true;
        if(bucket == target)    return backtrack(k-1, 0, nums, 0, vis, target);
        for(int i = start; i < nums.size(); i ++){
            if(vis[i]) continue;
            if(nums[i] + bucket > target)  continue;
            vis[i] = true;
            bucket += nums[i];
            if(backtrack(k, bucket, nums, i+1, vis, target))    return true;
            vis[i] = false;
            bucket -= nums[i];
        }
        return false;
    }

    bool canPartitionKSubsets1(vector<int>& nums, int k){
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % k > 0)   return false;
        int per = total / k, n = nums.size();
        // 降序排序
        sort(nums.begin(), nums.end(), [](int a, int b)->bool{return a>b;});
        bool vis[n];
        return backtrack(k, 0, nums, 0, vis, per);
    }
};