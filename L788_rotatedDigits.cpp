//
// Created by admin on 2022/9/27.
//
#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};

public:
    // 暴力枚举
    int rotatedDigits(int n){
        int res = 0;
        for(int i = 1; i <= n; i ++){
            string num = to_string(i);
            bool valid = true, diff = false;
            for(char ch:num){
                if(check[ch-'0'] == -1){
                    valid = false;
                }else if(check[ch-'0'] == 1)
                    diff = true;
            }
            if(valid && diff)
                res++;
        }
        return res;
    }

    // 数位dp
    int rotateDigits1(int n){





    }
};

int main(){

}