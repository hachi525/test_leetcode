//
// Created by admin on 2022/7/29.
//

#include "L593_validSquare.h"

/* 求两点间距离 */
long length(vector<int> x, vector<int> y){
    return 1L*(x[0]-y[0]) * (x[0]-y[0]) + 1L*(x[1]-y[1]) * (x[1]-y[1]);
}

/* 方法一： 求出6条边，四条边长和两条对角线。
 * 边长相等的只有正方形和菱形，对角线又相等的只有正方形
 * 所以排序判断边长以及对角线是否相等即可
 * */
bool L593_validSquare::validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
    if (p1[0] == p2[0] && p1[1] == p2[1])   return false;
    vector<long> edgeLens(6);
    edgeLens[0] = length(p1, p2);
    edgeLens[1] = length(p1, p3);
    edgeLens[2] = length(p1, p4);
    edgeLens[3] = length(p2, p3);
    edgeLens[4] = length(p2, p4);
    edgeLens[5] = length(p3, p4);
    sort(edgeLens.begin(), edgeLens.end());
    /*  for (auto len:edgeLens) {
        cout<< len << ", ";
    }*/
    return edgeLens[0] == edgeLens[3] && edgeLens[4] == edgeLens[5];
}

/* 方法二：
 * 1.两点连线中点，需要先找到对角线的两个点
 * 2.
 * 3.
 * */
bool L593_validSquare::validSquare1(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
    if (length(p1, p2) == length(p3, p4))
        ;
    if (p1 == p2)   return false;


}

/* 方法三：旋转90°后点应该一致
 *
 * */
#define Cen2Ori(p) {p[0]*4-centX, p[1]*4-centY}
bool L593_validSquare::validSquare2(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
    int centX = p1[0] + p2[0] + p3[0] + p4[0];
    int centY = p1[1] + p2[1] + p3[1] + p4[1];
    // 将中心点移动到坐标原点
    vector<array<int ,2> > pts = {Cen2Ori(p1), Cen2Ori(p2), Cen2Ori(p3), Cen2Ori(p4)};
    auto arrayHash = [fn = hash<long>{}] (const array<int, 2>& arr) -> size_t { // 哈希函数
        return fn(*((long const*)arr.data())); //使用横坐标生成哈希值
    };
    unordered_set<array<int, 2>, decltype(arrayHash)> pts_set(pts.begin(), pts.end(), 0, arrayHash);
    // 使用pts数组构造一个哈希set
    if (pts_set.size() < 4) return false;
    for (auto &pt:pts) {
        if (!pts_set.count({-pt[1], pt[0]}))
            return false;
    }
    return true;
}

/* 方法四：
 * 取三点作三角形，勾股定理判断等腰直角三角形，两个等腰直角三角形即为正方形
 * */

int main() {
    L593_validSquare solution;
//    solution.validSquare();
    return 0;
}
