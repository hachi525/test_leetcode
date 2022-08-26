//
// Created by admin on 2022/7/19.
//

#include "L565_arrayNesting.h"

/* 题述：
 * 索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。
 * 假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。
 * d[i] = A[d[i]]
 * d[i] <= nums.size()-1
 */

/* 方法一：两个set，一个存访问过的下标，一个存当前循环访问过的的集合，耗时耗空间，击败5% */
int L565_arrayNesting::arrayNesting(vector<int> &nums) {
    int maxNum = -1;
    set<int> hashSet;
    for (int i = 0; i < nums.size(); ++ i) {
        if(hashSet.count(i) != 1){
            set<int> d;
            int start = i;
            while (d.count(start)<1) {
                d.emplace(start);
                hashSet.emplace(start);
                start = nums[start];
            }
            maxNum = max(maxNum, (int)d.size());
        }
    }
    return maxNum;
}

/* 方法二：原地标记
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * */
int L565_arrayNesting::arrayNesting1(vector<int> &nums) {
    int maxNum = -1, n = nums.size();
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        while (nums[i] < n){
            int temp = nums[i];
            nums[i] = n;
            i = temp;
            ++ cnt;
        }
        maxNum = max(maxNum, cnt);
    }
    return maxNum;
}

/* 方法三： 图，标记数组
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * */
int L565_arrayNesting::arrayNesting2(vector<int> &nums) {
    int maxNum = -1, n = nums.size();
    vector<int> visited(n);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        while (!visited[i]){
            visited[i] = 1;
            i = nums[i];
            ++ cnt;
        }
        maxNum = max(maxNum, cnt);
    }
    return maxNum;
}

void Test(){
    vector<int> nums;
    // 输入nums
    L565_arrayNesting solution;
    cout << solution.arrayNesting(nums) << endl;
}

int main(){
    Test();
    return 0;
}