//
// Created by admin on 2022/7/20.
//

#include "L1260_shiftGrid.h"

/* 二维数组迁移，类似于一维数组循环右移
 * 解题思路： 1.转换为一维数组，然后数组左移(两部分分别反转，再整体反转)后再恢复为二维数组
 * */
vector<vector<int>> L1260_shiftGrid::shiftGrid(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    if(k%(m*n) == 0) return grid;   //base case
    k = k % (m*n);
    vector<vector<int> > res(m, vector<int> (n));
    // grid[i][j]移动k步后 列数：(k+j)%n,行数：((k+j)/n+i)%m
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res[((k+j)/n+i)%m][(k+j)%n] = grid[i][j];
        }
    }
    return res;
}

/* shift，调用emplace(iterator, elem)将每行末尾数字elem插到下一行开始 */
vector<vector<int>> L1260_shiftGrid::shiftGrid1(vector<vector<int>> &grid, int k) {
    for (int i = 0; i < k; ++i)
        shif(grid);
    return grid;
}

/* 对grid执行一次迁移操作 */
void L1260_shiftGrid::shif(vector<vector<int>> &grid) {
    int m = grid.size();
    for (int i = 0; i < m; ++i) {
        int a = grid[i].back(); //每一行的末尾数字
        grid[i].pop_back();
        grid[(i+1)%m].emplace(grid[(i+1)%m].begin(), a);
    }
}

vector<vector<int>> Test(){
    vector<vector<int> > grid;
    int k;
    cin >> k;
    // 输入二维矩阵
    L1260_shiftGrid* solution = new L1260_shiftGrid;
    return solution->shiftGrid(grid, k);
}

int main() {

    return 0;
}
