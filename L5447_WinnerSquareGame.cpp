//
// Created by admin on 2022/7/12.
//

#include "L5447_WinnerSquareGame.h"

// L5447_石子游戏
// 动态规划-自底向上
// dp[i]:i个石子时先手的胜负，true胜false负
bool L5447_WinnerSquareGame::winnerSquareGame(int n) {
    vector<bool> dp(n+1, false);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j*j <= i ; ++j) {// j*j为i个石子时先手拿走的石子
            if (!dp[i - j*j]){
                dp[i] = true;
                break;
            }  //dp[i-j*j]为i个石子时先手拿走j*j个石子时后手的胜负，如果为负，则先手胜
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    L5447_WinnerSquareGame solution;
    cout << boolalpha << solution.winnerSquareGame(n) << endl;  //boolapha可以打印bool值，而不是输出为0/1
    return 0;
}