//
// Created by admin on 2022/7/11.
//
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <stack>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>

#define LL long long
#define ULL usigned long long
#define inf 0x7fffffff
#define mod %100000007

const int nmax = 1000+10;
const int tmax = 100+10;    // 变迁最大数
const int pmax = 100+10;    // 库所最大数

int np, nt;         // 输入库所和变迁的个数
int A[tmax][pmax];  // 输入关联矩阵
int O1[tmax][pmax], O2[tmax][pmax]; // 输出矩阵A+，输入矩阵A-
int M0[pmax];       // 初始标识
int M[pmax], M1[pmax];  // 当前标识

#ifndef PROJECT_TYPE_H
#define PROJECT_TYPE_H

#endif //PROJECT_TYPE_H
