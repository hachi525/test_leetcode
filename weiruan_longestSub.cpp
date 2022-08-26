//
// Created by admin on 2022/8/26.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    bool evenLetter(const string& s){
        vector<int> cnt(26);
        for(auto& c:s){
            cnt[c-'a'] ++;
        }
        for(auto& num : cnt)
            if(num % 2 != 0)
                return false;
        return true;
    }

    int solution(string &S){
        int res = 0;
        for(int i = 0; i < S.size(); i ++){
            for(int j = 2; i + j -1 < S.size(); j += 2){
                string temp = S.substr(i, j);
                if(evenLetter(temp))
                    res = max(res, (int)temp.size());
            }
        }
        cout << res;
        return res;
    }
};

int main(){
    Solution sol;
    string a = "aaaaaaaaa";
    sol.solution(a);
    return 0;
}