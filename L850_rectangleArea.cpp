//
// Created by admin on 2022/9/16.
//

#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    const int MOD = (int)1e9+7;
public:
    int rectangleArea(vector<vector<int> >& rectangles){
        vector<int> vec;

        // 将所有的横坐标加入到数组中
        for(vector<int> rec:rectangles){
            vec.emplace_back(rec[0]);
            vec.emplace_back(rec[2]);
        }

        sort(vec.begin(), vec.end(), less<int>());

        long ans;
        for(int i = 1; i < vec.size(); i ++){
            int a = vec[i-1], b = vec[i], length = b-a;
            if(length == 0) continue;
            vector<vector<int>> lines;
            for(vector<int> rec : rectangles){
                if (rec[0] <= a && b <= rec[2])
                    lines.emplace_back(vector<int>{rec[1], rec[3]});
            }
            // 排序，升序
            sort(lines.begin(), lines.end(), [](vector<int> l1, vector<int> l2)->bool {
                return l1[0] != l2[0] ? l1[0] > l2[0] : l1[1] < l2[1];
            });
            long tot = 0, l = -1, r = -1;
            for (vector<int> cur : lines) {

            }

        }

    }
};

/// Lc 1624
// 字符串s中两个相同字符间的最长子字符串长度
class Sol{
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> idx(26, -1);
        int maxLength = -1;
        for(int i = 0; i < s.size(); i ++){
            if (idx[s[i]-'a'] < 0){
                idx[s[i]-'a'] = i;
            }else{
                maxLength = max(maxLength, i-idx[s[i]-'a']-1);
            }
        }
        return maxLength;
    }
};