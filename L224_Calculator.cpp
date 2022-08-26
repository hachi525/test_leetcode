//
// Created by admin on 2022/7/27.
//

#include "L224_Calculator.h"

/* 将字符串中所有的空格剔除 */
void L224_Calculator::replaceSpace(string &s) {
    int pos = s.find(" ");
    while (pos != -1){
        s.replace(pos, 1, "");
        pos = s.find(" ");
    }
}

/* 只支持加减运算，如果要加入乘除则需要将最后一行修改 */
void L224_Calculator::calculate(stack<int> &nums, stack<char> &ops) {
    if (nums.size() < 2 || ops.empty())
        return;
    int num1 = nums.top(); nums.pop();
    int num2 = nums.top(); nums.pop();
    char op = ops.top(); ops.pop();
    nums.push(op=='+'? num1+num2 : num1-num2);
}

int L224_Calculator::calculator(string s) {
    stack<int> nums;
    stack<char> ops;
    replaceSpace(s);
    int n = s.size();
    nums.push(0);
    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        if (ch == '('){
            ops.push(ch);
        } else if (ch == ')'){
            while (!ops.empty()){
                char op = ops.top();
                if (op != '(')
                    calculate(nums, ops);
                else{
                    ops.pop();
                    break;
                }
            }
        } else{
            if (isdigit(ch)){
                int j = i, num = 0;
                while (j < n && isdigit(s[j]))
                    num = num*10 + (s[j++] - '0');
                nums.push(num);
                i = j-1;
            } else {
                if (i > 0 && (s[i-1]=='+' || s[i-1]=='-' || s[i-1] == '(' ))
                    nums.push(0);
                while (!ops.empty() && ops.top() != '(')
                      calculate(nums, ops);
                ops.push(ch);
            }
        }
    }
    while(!ops.empty())
        calculate(nums, ops);
    return nums.top();
}

int main() {
    L224_Calculator solution;
    string s = "-1+3+(-5-3)";
    cout << solution.calculator(s) << endl;
    return 0;
}
