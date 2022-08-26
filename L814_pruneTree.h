//
// Created by admin on 2022/7/21.
//

#ifndef PROJECT_L814_PRUNETREE_H
#define PROJECT_L814_PRUNETREE_H
#ifndef _L814_pruneTree_H_
#define _L814_pruneTree_H_


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;    // 0/1
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class L814_pruneTree {
public:
    TreeNode *pruneTree(TreeNode *root);
};


#endif //_L814_pruneTree_H_
#endif //PROJECT_L814_PRUNETREE_H
