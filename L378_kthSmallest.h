//
// Created by admin on 2022/7/12.
//

#ifndef PROJECT_L378_KTHSMALLEST_H
#define PROJECT_L378_KTHSMALLEST_H

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class L378_kthSmallest {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k);    //暴力1
    int kthSmallest1(vector<vector<int>>& matrix, int k);   //暴力2
    int kthSmallest2(vector<vector<int>>& matrix, int k);   //归并
    int kthSmallest3(vector<vector<int>>& matrix, int k);   //二分
};


#endif //PROJECT_L378_KTHSMALLEST_H
