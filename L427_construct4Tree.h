//
// Created by admin on 2022/7/18.
//

#ifndef PROJECT_L427_CONSTRUCT4TREE_H
#define PROJECT_L427_CONSTRUCT4TREE_H

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class L427_construct4Tree {
    vector<vector<int> > g;
    vector<vector<int>> sum;    //前缀和
public:
    Node* construct(vector<vector<int>>& grid);
    Node* dfs(int a, int b, int c, int d);
    Node* construct1(vector<vector<int>>& grid);
    Node* dfs1(int a, int b, int c, int d);
};


#endif //PROJECT_L427_CONSTRUCT4TREE_H
