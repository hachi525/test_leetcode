//
// Created by admin on 2022/7/13.
//

#include "En_1024contest.h"

/* 参赛人数为X，分组为N的总题数为 dp[X-1][N-1]*/

int En_1024contest::contest(int X, int N, vector<int> abilities) {
    vector<pair<int, int> > group;
    int topics = 0, sum = 0;

    for (int ability:abilities) {
        sum += ability;
    }
    bool flag = true;
    if(X%N == 0 && sum%N == 0)
        int avg = sum/N;    // 理想情况下平均每个组的能力值
    int pre = 0;
    for (int i = 0, j = 0; i < N; ++i) {
        while (j < X) {
            if(group[i].second == pre){
                topics += 2;
                break;
            } else if (group[i].second + abilities[j] > pre){
                topics += 3;
                break;
            }
            group[i].first++;   // 第i组的人数
            group[i].second += abilities[j];    // 第i组的能力总值
        }
        pre = group[i].second;
    }
    return topics;
}