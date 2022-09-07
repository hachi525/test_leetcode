//
// Created by admin on 2022/9/7.
//
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

#include <algorithm>
using namespace std;

class Solution{
public:
    /* 统计字符串 s 中的唯一字符，并返回唯一字符的个数 */
    int countUniqueChars(string s);
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int> > map;
        for(int i = 0; i < s.size(); i ++){
            map[s[i]].emplace_back(i);
        }

        int res = 0;
        for(auto& [_, arr]: map){
            arr.insert(arr.begin(), -1);
            arr.emplace_back(arr.size());

            for(int i = 1; i < arr.size()-1; i ++){
                res += (arr[i] - arr[i-1]) * (arr[i+1] - arr[i]);
            }
        }
        cout << res << endl;
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    string str;
    cin >> str;
    solution->uniqueLetterString(str);
    return 0;
}