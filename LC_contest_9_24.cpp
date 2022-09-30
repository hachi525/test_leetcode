//
// Created by admin on 2022/9/24.
//
#include <bits/stdc++.h>

using namespace std;

/* 第一题:气温变化趋势 */
int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
    int n = temperatureA.size();
    vector<int> differA(n);
    vector<int> differB(n);

    int cur = 0;
    int res = 0;
    for(int i = 1; i < n; i ++){
        differA[i] = temperatureA[i] - temperatureA[i-1] > 0 ? 1 : (temperatureA[i] - temperatureA[i-1]) == 0 ? 0 : -1;
        differB[i] = temperatureB[i] - temperatureB[i-1] > 0 ? 1 : (temperatureB[i] - temperatureB[i-1]) == 0 ? 0 : -1;
        if(differA[i] == differB[i])
            cur ++;
        else{
            res = max(res, cur);
            cur = 0;
        }
    }
    res = max(res, cur);
    return res;
}

/* 第二题：找出交通枢纽（n个结点，入度为n-1，出度为0即为交通枢纽） */
int transportationHub(vector<vector<int>>& path) {
    vector<int> indegree(1010, 0);
    vector<int> outdegree(1010, 0);
//    for(int i = 0; i < path.size(); i++){
//        for(int j = 0; j < path[0].size(); j ++){
//            if(path[i][j] == 1){
//                indegree[j] ++;
//                outdegree[i] ++;
//            }
//        }
//    }
    int n = 0;
    for(auto& item : path){
        outdegree[item[0]] ++;
        indegree[item[1]] ++;
        n = max({n, item[0], item[1]});
    }


    for(int i = 0; i <= n; i ++){
        if(indegree[i] == n && !outdegree[i])
            return i;
    }
    return -1;
}



int main(){
    /* 第一题测试 */
    vector<int> d = {21,18,18,18,31};
    vector<int> c = {34,32,16,16,17};
//    vector<int> d = {1,-15,3,14,-1,4,35,36};
//    vector<int> c = {-15,32,20,9,33,4,-1,-5};
    temperatureTrend(d, c);




}