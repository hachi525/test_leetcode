//
// Created by admin on 2022/8/31.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;

class Solution{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int n = pushed.size();
        for(int i = 0, j = 0; i < n ; i ++){
            st.emplace(pushed[i]);
            while(!st.empty() && popped[j] == st.top()){
                st.pop();
                j ++;
            }
        }
        return st.empty();
    }
};

void trimLeftTrailingSpaces(string &input) {
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

vector<int> stringToIntegerVector(string input) {   // string - vector<int>
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
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

