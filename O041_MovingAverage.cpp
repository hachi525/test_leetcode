//
// Created by admin on 2022/7/16.
//

#include "O041_MovingAverage.h"

/* 给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值
 * 请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。
 */
O041_MovingAverage::O041_MovingAverage(int size) {
    _size = size;
    sum = 0.0;
}

double O041_MovingAverage::next(int val) {
    if(que.size() == this->_size){
        sum -= que.front();
        que.pop();
    }
    que.emplace(val);
    sum += val;
    return sum/que.size();
}

void Test(){
    O041_MovingAverage* movingAverage = new O041_MovingAverage(3);
    cout << movingAverage->next(1)<< endl;
    cout << movingAverage->next(10)<< endl;
    cout << movingAverage->next(3)<< endl;
    cout << movingAverage->next(5)<< endl;
}


int main(){
    Test();
    return 0;
}