//
// Created by admin on 2022/7/16.
//

#ifndef PROJECT_O041_MOVINGAVERAGE_H
#define PROJECT_O041_MOVINGAVERAGE_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


class O041_MovingAverage {
private:
    int _size;
    double sum;
    queue<int> que;

public:
    /** Initialize your data structure here. */
    O041_MovingAverage(int size);   //用窗口大小 size 初始化对象。
    double next(int val);   //成员函数 next每次调用的时候都会往滑动窗口增加一个整数
};


#endif //PROJECT_O041_MOVINGAVERAGE_H
