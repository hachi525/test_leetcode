//
// Created by admin on 2022/7/27.
//

#ifndef PROJECT_L224_CALCULATOR_H
#define PROJECT_L224_CALCULATOR_H
#ifndef _L224_Calculator_H_
#define _L224_Calculator_H_


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class L224_Calculator {
public:
    void calculate(stack<int>& nums, stack<char>& ops);
    void replaceSpace(string& s);
    int calculator(string s);
};


#endif //_L224_Calculator_H_
#endif //PROJECT_L224_CALCULATOR_H
