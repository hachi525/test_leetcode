//
// Created by admin on 2022/7/8.
//
#include <vector>

using namespace std;

#ifndef PROJECT_KTHPRIMEFRACTION_H
#define PROJECT_KTHPRIMEFRACTION_H


class Solution {
public:
    /**
    unordered_map<int, int> pos;
    struct cmp{
        bool operator()(pair<int, int>x, pair<int, int> y){
            return x.first*y.second>x.second*y.first;
        }
    };
    */
    int n, a, b;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        /** 一、优先队列法
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
        vector<int> ans;

        for(int i = 0; i < arr.size(); i ++){
            pos[arr[i]]  = i;
        }

        for(int i = 1; i < arr.size(); i++){
            pq.push(make_pair(arr[0], arr[i]));
        }

        for(int i = 0; i < k-1; i ++){
            auto p = pq.top();
            pq.pop();
            pq.push(make_pair(arr[pos[p.first]+1], p.second));
        }
        auto p = pq.top();
        ans.push_back(p.first);
        ans.push_back(p.second);
        return ans;
        */

        /* 二、二分法+双指针 */
        n = arr.size();
        double l = 0, r = 1;

        while(true){
            double mid = (l+r)/2;
            int cnt = count(mid, arr);
            if(cnt > k) r = mid;
            else if(cnt < k) l = mid;
            else break;
        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }

    int count(double x, vector<int>& arr){
        int res = 0;
        double max = 0;
        for(int i = 0, j = 1; j < arr.size(); j ++){
            while(arr[i+1]*1.0 / arr[j] <= x)
                i ++;
            if(arr[i]*1.0 / arr[j] <= x){
                res += i+1;
                if(arr[i]*1.0 / arr[j] > max){
                    a = arr[i];
                    b = arr[j];
                    max = arr[i]*1.0 / arr[j];
                }
            }
        }
        return res;
    }
};


#endif //PROJECT_KTHPRIMEFRACTION_H
