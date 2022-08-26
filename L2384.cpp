//
// Created by admin on 2022/8/25.
//

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        int cnt[10] = {0};
        for(char c : num) cnt[c-'0']++;
        string res;

        for(int i = 9; i; i --)
            if(cnt[i] >= 2){
                res = to_string(i);
                cnt[i] -= 2;
                break;
            }

        if(res == "")
            for(int i = 9; i >= 0; i --){
                if(cnt[i])
                    return to_string(i);
            }

        for(int i = 9; i >= 0; i --){
            while(cnt[i] >= 2){
                res += to_string(i);
                cnt[i] -=  2;
            }
        }

        string reverseStr = res;
        reverse(reverseStr.begin(), reverseStr.end());

        for(int i = 9; i >= 0; i --){
            if(cnt[i]) {
                res += to_string(i);
                break;
            }
        }

        return res + reverseStr;
    }
};

int main(){
    Solution solution;
    solution.largestPalindromic("00001105");
    return 0;
}