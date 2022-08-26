//
// Created by admin on 2022/7/12.
//
#include "OddCells.h"

// L1252_奇数值单元格的数目
/* 方法一：矩阵模拟+暴力求解，时间O(q*(m+n)+mn) q为indices长度，空间O(mn) */
int OddCells::oddCells(int m, int n, vector<vector<int>> &indices) {
    int cnt = 0;
    vector<vector<int> > temp(m, vector<int>(n, 0));    //创建初始矩阵
    for (auto &indice: indices) {
        int row = indice[0], col = indice[1];   //需要自增的行和列
        for (int i = 0; i < n; ++i) //某一行自增
            temp[row][i] ++;
        for (int i = 0; i < m; ++i) //某一列自增
            temp[i][col] ++;
    }

    for (int i = 0; i < m; ++i) {//找奇数
        for (int j = 0; j < n; ++j) {
            if (temp[i][j] & 1)
                cnt++;
        }
    }
    return cnt;
}

/* 方法二：模拟优化，记录每一行每一组自增次数,时间O(q+ m*n),空间O(m+n) */
int OddCells::oddCells1(int m, int n, vector<vector<int>> &indices) {
    vector<int> row(m, 0);
    vector<int> col(n, 0);

    // 计算自增次数
    for (auto &indice : indices) {
        row[indice[0]] ++;
        col[indice[1]] ++;
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if((row[i] + col[j]) & 1)   cnt ++;
    return  cnt;
}

/* 方法三：计数优化，计算奇数个数时的优化,时间O(m+n+q),空间O(m+n) */
int OddCells::oddCells2(int m, int n, vector<vector<int>> &indices) {
    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for (auto &indice : indices) {// 计算自增次数
        row[indice[0]] ++;
        col[indice[1]] ++;
    }

    int rowOdds = 0, colOdds = 0;
    for (int i = 0; i < m; ++i) // 统计自增次数为奇数的行
        if(row[i] & 1) ++ rowOdds;
    for (int i = 0; i < n; ++i) // 统计自增次数为奇数的列
        if(col[i] & 1) ++ colOdds;
    return rowOdds*n + colOdds*m - 2*rowOdds*colOdds;
    // rowOdds*n：按行计自增奇数次的个数；
    // colOdds*m：按列计自增奇数次的个数；
    // 2*rowOdds*colOdds：前面两者交叉重复的个数，因为行列交叉的地方自增了（行奇数次+列奇数次）偶数次
}