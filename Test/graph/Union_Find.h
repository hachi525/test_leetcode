//
// Created by admin on 2022/7/30.
//

#ifndef PROJECT_UNION_FIND_H
#define PROJECT_UNION_FIND_H
#ifndef _Union_Find_H_
#define _Union_Find_H_


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Union_Find {
private:
    int count; //连通分量
    vector<int> parent;
public:
    Union_Find(int n):count(n){

    }
};

class DisjSet{
private:
    vector<int> parent; // 祖先结点
    vector<int> rank;   // 树的深度，秩
    int count;          // 联通分量的数量
    vector<int> size;
public:
    DisjSet(int max_size):parent(vector<int>(max_size)), count(max_size){
        for (int i = 0; i < max_size; ++i) {
            parent[i] = i;
        }
    }

    /* 路径压缩 将x到祖先节点间所有节点都改为祖先节点的子结点，这样树的高度变成2 */
    int find(int x){//路径压缩为高度为2的树
        return parent[x] == x ? x : (parent[x] = find(parent[x]));// 递归
    }

    /* 将两个节点联通O(1) */
    void to_union(int x1, int x2){
        if (find(x1) == find(x2)) // 相同祖先节点，已经联通
            return;
        parent[x1] = find(x2);
        count --;
    }

    /* 判断是否属于一个集合O(1) */
    bool is_same(int e1, int e2){
        return find(e1) == find(e2);
    }

    /* 联通分量O(1) */
    int u_count(){
        return count;
    }

};


#endif //_Union_Find_H_
#endif //PROJECT_UNION_FIND_H
