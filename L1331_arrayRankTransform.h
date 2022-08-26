//
// Created by admin on 2022/7/28.
//

#ifndef PROJECT_L1331_ARRAYRANKTRANSFORM_H
#define PROJECT_L1331_ARRAYRANKTRANSFORM_H
#ifndef _L1331_arrayRankTransform_H_
#define _L1331_arrayRankTransform_H_


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class L1331_arrayRankTransform {
private:
    unordered_map<int , int> map;
public:
    vector<int> arrayRankTransform(vector<int>& arr);
};


#endif //_L1331_arrayRankTransform_H_
#endif //PROJECT_L1331_ARRAYRANKTRANSFORM_H
