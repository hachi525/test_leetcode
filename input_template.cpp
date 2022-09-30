//
// Created by admin on 2022/8/31.
//

#include <string>
#include <sstream>
#include <iostream>

#include <algorithm>

#include <vector>
#include <queue>

#include "Ds_binaryTree.h"


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

/*
 * 单行字符串input: 二维数组型字符串，如"[[1,2,3], [1,2,3], [3,3,4]]"
 * */
vector<vector<int> > stringToVector(string input){
    vector<vector<int> > output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    input = "," + input;
    stringstream ss(input);
    char delim = ',';
    char delim1 = ']';
    string item;
    while (getline(ss, item, delim1)) {
        vector<int> temp;
        item = item.substr(2, item.length()-2);
        stringstream ss1(item);
        string num;
        while(getline(ss1, num, delim)){
            temp.emplace_back(stoi(num));
        }
        output.emplace_back(temp);
    }
    return output;
}
/*
 * 多行输入字符串转二维数组
 * 如：
 *  [
 *      [1,2,3],
 *      [2,3,4],
 *      [3,4,5]
 *  ]
 * */
void inputToVector(vector<vector<int>>& input){
    int cnt = 0;
    string line;
    char delim = ',';
    while(getline(cin, line)){
        trimLeftTrailingSpaces(line);
        trimRightTrailingSpaces(line);
        if(line == "]") break;
        if(line.size() == 1)    continue;
        if(line[line.length()-1] == ',')
            line = line.substr(1, line.length()-3);
        else
            line = line.substr(1, line.length()-2);
        stringstream ss(line);
        string tempString;
        vector<int> tempVector;
        while(getline(ss, tempString, delim)){
            tempVector.emplace_back(stoi(tempString));
        }
        input.emplace_back(tempVector);
    }
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

    // 以数组形式字符串输出，如[1, 2, 3, 4, 5]
    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    // length-2是因为在上述for循环最后一次时字符串后增加了长度为2的字符串", "
    return "[" + result.substr(0, result.length() - 2) + "]";
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        // 构建node左孩子节点
        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        // 构建node右孩子节点
        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
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