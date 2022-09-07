//
// Created by admin on 2022/9/7.
//
#include <string>
#include <algorithm>
#include <vector>

#include <iostream>
#include <sstream>
using namespace std;

class Solution{
public:
    string reorderSpaces(string text){
        string res = "";
        vector<string> strVec;
        int spaceCnt = count(text.begin(), text.end(), ' ');

        stringstream ss(text);
        while(ss >> text) strVec.emplace_back(text);

        // 只有一个单词
        if(strVec.size() == 1){
            res.append(strVec[0]);
            res += string(spaceCnt, ' ');
            return res;
        }

        int gapSpaceCnt = spaceCnt/(strVec.size()-1); // 字符串间空格数量
        int restSpace = spaceCnt%(strVec.size()-1); // 末尾空格数量
        int n = 0;

        for(auto str:strVec){
            res += str;
            if(n >= strVec.size()-1) break;
            res.append(gapSpaceCnt, ' ');
            n ++;
        }
        if(restSpace) res.append(restSpace, ' ');
        return res;
    }
};

int main (){
    Solution* solution = new Solution();
    solution->reorderSpaces(" practice   makes   perfect");
    return 0;
}