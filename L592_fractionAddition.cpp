//
// Created by admin on 2022/7/27.
//

#include "L592_fractionAddition.h"
/* 给定一个表示分数加减运算的字符串expression，你需要返回一个字符串形式的计算结果
 * 这个结果应该是不可约分的分数，即最简分数。
 * 如果最终结果是一个整数，例如2，你需要将它转换成分数形式，其分母为1。所以在上述例子中, 2应该被转换为2/1。
*/

/* 辗转相除法求最大公约数,用于约分 */
long long gcd(long long a, long long b) {
    return b == 0?a: gcd(b, a%b);
}

/* 计算两个分数字符串，返回结果字符串，下面代码问题在于a,b,c,d的值不对，如果是多位数得一位一位算
 * string fractionAdd(char opt, string num1, string num2){
    int a = (int)num1[0]-'0', b = (int)num1[2]-'0';
    int c = (int)num2[0]-'0', d = (int)num2[2]-'0';
    cout << a <<endl;
    long long denominator = (opt == '+'?a*d+c*b:a*d-c*b), numerator = b*d;
    long long g = gcd(denominator, numerator);
    cout << "denominator=" << denominator<< ",numerator" << numerator << ",gcd = "<< g << endl;
    if (g != 0) denominator/=g;
    if(denominator == 0)
        return "0/1";
    numerator/=g;
    return to_string(denominator)+"/"+ to_string(numerator);
}*/

string L592_fractionAddition::fractionAddition(string expression) {
    /* 方法一： 简单模拟 */
    long long denominator = 0, numerator = 1;
    int idx = 0, n = expression.size();
    while (idx < n) {
        long long denominator1 = 0, sign = 1;
        if (expression[idx] == '-' || expression[idx] == '+') {
            sign = expression[idx] == '-' ? -1 : 1;
            idx++;
        }
        while (idx < n && isdigit(expression[idx])) {
            denominator1 = denominator1 * 10 + expression[idx] - '0';
            idx++;
        }
        denominator1 *= sign;
        idx++;

        long long numerator1 = 0;
        while (idx < n && isdigit(expression[idx])) {
            numerator1 = numerator1 * 10 + expression[idx] - '0';
            idx++;
        }
        denominator = denominator1 * numerator + denominator * numerator1;
        numerator *= numerator1;
    }
    if (denominator == 0) return "0/1";
    long long g = gcd(abs(denominator), numerator);
    return to_string(denominator / g) + "/" + to_string(numerator / g);

    /* 方法二： 双栈计算 */
/*    stack<char> opt;
    stack<string> fraction;
    string temp;
    temp.clear();
    temp = "0/1";
    int i;
    i = 0;
    for (char& ch:expression) {// 分割字符串
        if (ch == '+' || ch == '-' ) {
            opt.emplace(ch);
            fraction.emplace(temp);
            cout << "the " << ++i << "th split, temp = " << temp << endl;
            temp.clear();
            continue;
        }
        temp.push_back(ch);
    }
    fraction.emplace(temp);

    cout << "-------------split over!-------------" << endl ;
    i = 0;
    while (!opt.empty()){
        string num1 = fraction.top();
        fraction.pop();
        string num2 = fraction.top();
        fraction.pop();
        cout<< "num1 = " << num1 << ", num2 = " << num2 <<endl;
        expression = fractionAdd(opt.top(), num1, num2);
        cout<< "the " << ++i << "th caculate:" << expression <<endl;
        fraction.push(expression);
        opt.pop();
    }
    cout << "solution = "<< expression << endl;
    return expression;*/
}

int main() {
    L592_fractionAddition solution;
    string expression = "1/3-1/2";
    return 0;
}
