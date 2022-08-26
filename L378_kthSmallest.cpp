//
// Created by admin on 2022/7/12.
//

#include "L378_kthSmallest.h"

//有序矩阵中第 K 小的元素

/* 暴力1-优先队列-小根堆 */
int L378_kthSmallest::kthSmallest(vector<vector<int> > &matrix, int k) {//暴力
    //priority_queue<int> pq; //默认大根堆
    priority_queue<int, vector<int>, greater<int> > pq; //创建小根堆
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            pq.push(matrix[i][j]);
        }
    }
    int res = 0;
    for (int i = 0; i < k; ++i) {
        if(i == k-1)
            res = pq.top();
        pq.pop();
    }
    return res;
}

/* 暴力2-vector使用sort排序 */
int L378_kthSmallest::kthSmallest1(vector<vector<int>> &matrix, int k) {
    vector<int> rec;
    for(auto &row:matrix)
        for (int it:row) {
            rec.push_back(it);
        }
    sort(rec.begin(), rec.end());
    return rec[k-1];
}

/* 多路归并 */
int L378_kthSmallest::kthSmallest2(vector<vector<int>> &matrix, int k) {
    struct point{
        int val, x, y;
        point(int val, int x, int y){
            this->val = val;
            this->x = x;
            this->y = y;
        }
        // 结构体构造函数简写： point(int val, int x, int y) : val(val), x(x), y(y){}
        bool operator> (const point& a) const{return this->val > a.val;}    //对point变量的运算符>重载
    };
    priority_queue<point, vector<point>, greater<point> > pq;
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        pq.emplace(matrix[i][0], i, 0);
    }

    for (int i = 0; i < k - 1; ++i) {
        point now = pq.top();
        pq.pop();
        if(now.y != n-1)
            pq.emplace(matrix[now.x][now.y+1], now.x, now.y+1);
    }
    return pq.top().val;
}

/* 二分法：矩阵左上角和左下角分别为最大最小值，
 *        矩阵中其他位置任意数mid左上部分都是小于mid的值，找到数量=k的就是所求结果
 * 时间复杂度：O(nlog(r-l)),二分查找次数O(log(r-l))，每次查找时间O(n)
 * 空间复杂度：O(1)
 * 左闭右开，二分搜索左边界
 * */
bool check(vector<vector<int> > &matrix, int mid, int k, int n){
    int i = n-1, j = 0, num = 0;
    while (i >= 0 && j < n){
        if (matrix[i][j] <= mid){
            num += i + 1;
            j ++;
        } else
            i --;
    }
    return num >= k;
}

int L378_kthSmallest::kthSmallest3(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n-1][n-1];
    while (left < right){
        int mid = left + (right - left)/2;
        if (check(matrix, mid, k, n))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}


int main(){
    vector<vector<int> > matrix;
    // 输入matrix矩阵
    int k;
    cin >> k;
    L378_kthSmallest solution;
    return solution.kthSmallest(matrix, k);
}