//
// Created by admin on 2022/7/23.
//

#include "L763_partitionLabels.h"

/* 字符串 S 由小写字母组成。
 * 我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
 * 返回一个表示每个字符串片段的长度的列表。
 * 思路：贪心算法
 * 最优子结构 +
 * */
vector<int> L763_partitionLabels::partitionLabels(string s) {
    vector<int> lastIdx(26);
    for (int i = 0; i < s.size(); ++i) {// 记录每一个字母最后出现的下标位置
        lastIdx[s[i]-'a'] = i;
    }
    int left = 0, right = INT_MIN;
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
        right = max(right, lastIdx[s[i]-'a']);
        if(right == i) {
            res.push_back(right - left + 1);
            left = right+1;
        }
    }
    return res;
}

int main() {

    return 0;
}
