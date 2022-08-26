//
// Created by admin on 2022/7/22.
//

#include "L757_intersectionSizeTwo.h"

/* 一个整数区间[a, b](a < b) 代表着从a到b的所有连续整数，包括a和b。
 * 给你一组整数区间intervals，请找到一个最小的集合 S，
 * 使得 S 里的元素与区间intervals中的每一个整数区间都至少有2个元素相交。
 * 输出这个最小集合S的大小。
 */

/* 方法一：逆向寻找，官解，
 * 问题：例子[[1,2],[2,3],[2,4],[4,5]]
 * 排序后会为[[1,2],[2,4],[2,3],[4,5]]
 * 在外层for循环会出现i=0时，k=1,help传进去的i-1此时为-1，不进入for循环
 * 虽然并不会影响最终res的值是对的
 * */
void L757_intersectionSizeTwo::help(vector<vector<int>>& intervals, vector<vector<int>>& temp, int pos, int num){
    for (int i = pos; i >= 0; --i) {
        cout << "intervals["<< i <<"][1] = "<< intervals[i][1] <<endl;
        if (intervals[i][1] < num)
            break;
        temp[i].push_back(num);
        cout << "num = " << num <<  "\n" << endl;
    }
}
int L757_intersectionSizeTwo::intersectionSizeTwo(vector<vector<int>> &intervals) {
    // 自定义比较规则，v[0]升序，v[1]降序
    struct cmp{
        bool operator()(const vector<int>&v1, const vector<int>&v2){
            return v1[0]==v2[0]?v1[1]>v2[1]:v1[0]<v2[0];
        }
    };
    sort(intervals.begin(), intervals.end(), cmp());
    int n = intervals.size(), res = 0;
    vector<vector<int> > temp(n);
    for (int i = n-1; i >= 0; i--) {
        cout << "---------"<< i <<"th for----------" << endl;
        for (int j = intervals[i][0], k = temp[i].size(); k < 2; ++j, ++k) {
            res++;
            cout << "j = "<< j << ", k = " << k << ", res++ ,res = " << res << endl;
            help(intervals, temp, i-1, j);
        }
    }
    return res;
}

/* 方法二： 正向寻找，从前往后先v[1]升序，再v[0]降序，每次取最大的*/
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto &a, const auto &b) {
            return a[1] != b[1] ? a[1] < b[1] : a[0] > b[0];
        });//先v[1]升序，再v[0]降序
        int n = intervals.size(), a = -1, b = -1, res = 0;
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] > b) {  // 需要添加两个点
                res += 2;
                a = intervals[i][1] - 1;
                b = intervals[i][1];
            } else if (intervals[i][0] > a) { // <= b 需要添加一个点
                a = b;
                b = intervals[i][1];
                res += 1;
            }
        }
        return res;
    }
};

void Test(){
    vector<vector<int> > intervals;
    vector<int> A;
    A.push_back(1);A.push_back(2);
    intervals.push_back(A);
    A.clear();
    A.push_back(2);A.push_back(4);intervals.push_back(A);
    A.clear();
    A.push_back(2);A.push_back(3);intervals.push_back(A);
    A.clear();
    A.push_back(4);A.push_back(5);intervals.push_back(A);
    L757_intersectionSizeTwo solution;
    solution.intersectionSizeTwo(intervals);
}

int main() {
    Test();

    return 0;
}
