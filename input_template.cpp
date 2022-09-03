//
// Created by admin on 2022/8/31.
//

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{

};

void trimLeftTrailingSpaces(string &input) { // 删除起始的空白字符
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

/* base是reverse_iterator的成员函数，
 * reverse_iterator是通过普通的iterator实现的，
 * base的作用是获得这个内部的iterator。
 * trimRightTrailingSpaces函数的作用是删除末尾的空白字符。
 * */
void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}
/*
 * input: 数组型字符串，如"[1, 2, 3]"
 * */
vector<int> stringToIntegerVector(string input) {   // string - vector<int>
    vector<int> output;
    // 删除起止的空白字符
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);

    // string.substr(pos, length): 抽去一个子串
    // 去除输入字符串首尾的'[' ']'
    input = input.substr(1, input.length() - 2);

    // 字符串流
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        // stoi(str) : 解析str的文本转化为为int整数
        // 函数模板：int stoi (const string& str, size_t* idx = 0, int base = 10);
        // 函数模板：int stoi (const wstring& str, size_t* idx = 0, int base = 10);

        // atoi(str)，解析字符串返回int，不会抛出异常
        // 函数模板：int atoi (const char * str);
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {   // bool - string
    return input ? "True" : "False";
}

string integerVectorToString(vector<int> list, int length = -1) { // vector<int> - string数组字符串
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    // length-2是因为在上述for循环最后一次时字符串后增加了长度为2的字符串", "
    return "[" + result.substr(0, result.length() - 2) + "]";
}


int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> pushed = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> popped = stringToIntegerVector(line);

        bool ret = Solution().validateStackSequences(pushed, popped);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
} 