//
// Created by admin on 2022/7/20.
//

#include "L719_smallestDistancePair.h"
/* 数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
 * 给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length 。
 * 返回 所有数对距离中 第 k 小的数对距离。
*/

/* 方法1：暴力+优先队列或者用sort排序，但是需要自定义比较规则
 * 容易超时:确实超时了=-=
*/
int L719_smallestDistancePair::smallestDistancePair(vector<int> &nums, int k) {
    struct cmp{//自定义比较函数，升序，建小根堆
        bool operator()(pair<int, int> a, pair<int, int> b){
            return abs(a.first-a.second) > abs(b.first-b.second);
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            pq.push(make_pair(nums[i], nums[j]));
        }
    }

    for (int i = 0; i < k - 1; ++i) {
        pq.pop();
    }
    return abs(pq.top().first-pq.top().second);
}


/* 方法2 排序+二分
 * 时间复杂度：O(nlogn*logD)
 * 空间复杂度：O(logn)
*/
int L719_smallestDistancePair::smallestDistancePair1(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end()); //先升序排序
    int left = 0, right = nums.back()-nums.front(), n = nums.size();
    while (left <= right){
        int cnt = 0, mid = left + (right - left)/2;
        for (int j = 0; j < n; ++j) {
            int i = lower_bound(nums.begin(), nums.begin()+j, nums[j] - mid) - nums.begin();
            // lower_bound(begin, end, val) 指定范围内 >= val的第一个数
            // 求满足nums[j]-nums[i]<= mid的数对下标(i,j)个数，即求nums[j]-mid <= nums[i]的个数，
            // 找到i后，j-i就是满足以上条件时以j为右端点的数对个数
            cnt += j-i;
        }
        if(cnt >= k)    right = mid - 1;
        else    left = mid + 1;
    }
    return left;
}

/* 排序 + 二分 + 双指针， 找左边界的二分搜索
 * 时间复杂度：O(n×(logn+logD)),外层二分查找需要O(logD)
 * 空间复杂度：O(logn)
*/
int L719_smallestDistancePair::smallestDistancePair2(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), left = 0, right = nums.back()-nums.front();
    while (left <= right){
        int cnt = 0, mid = left + (right-left)/2;
        for (int i = 0, j = 0; j < n; ++j) {
            while (nums[j] - nums[i] > mid) i ++;
            cnt += j-i;
        }
        if(cnt >= k)    right = mid - 1;
        else    left = mid + 1;
    }
    return left;
}

int main(){
    vector<int> nums(1000000);

    int k;
    cin >> k;
    L719_smallestDistancePair solution;
    solution.smallestDistancePair1(nums, k);
    return solution.smallestDistancePair(nums, k);
}
