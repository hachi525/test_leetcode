//
// Created by admin on 2022/7/20.
//

#ifndef PROJECT_L719_SMALLESTDISTANCEPAIR_H
#define PROJECT_L719_SMALLESTDISTANCEPAIR_H
#ifndef _L719_smallestDistancePair_H_
#define _L719_smallestDistancePair_H_


#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class L719_smallestDistancePair {
public:
    bool operator>(const pair<int, int> a);
    int smallestDistancePair(vector<int>& nums, int k);
    int smallestDistancePair1(vector<int>& nums, int k);
    int smallestDistancePair2(vector<int>& nums, int k);
};


#endif //_L719_smallestDistancePair_H_
#endif //PROJECT_L719_SMALLESTDISTANCEPAIR_H
