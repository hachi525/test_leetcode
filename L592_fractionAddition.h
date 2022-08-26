//
// Created by admin on 2022/7/27.
//

#ifndef PROJECT_L592_FRACTIONADDITION_H
#define PROJECT_L592_FRACTIONADDITION_H
#ifndef _L592_fractionAddition_H_
#define _L592_fractionAddition_H_


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
/*输入和输出字符串只包含'0' 到'9'的数字，以及'/', '+' 和'-'。
输入和输出分数格式均为±分子/分母。如果输入的第一个分数或者输出的分数是正数，则'+'会被省略掉。
输入只包含合法的最简分数，每个分数的分子与分母的范围是[1,10]。如果分母是1，意味着这个分数实际上是一个整数。
输入的分数个数范围是 [1,10]。
最终结果的分子与分母保证是 32 位整数范围内的有效整数。*/
class L592_fractionAddition {
public:
    string fractionAddition(string expression);
};


#endif //_L592_fractionAddition_H_
#endif //PROJECT_L592_FRACTIONADDITION_H
