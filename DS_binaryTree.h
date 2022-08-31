//
// Created by admin on 2022/8/30.
//

#ifndef PROJECT_DS_BINARYTREE_H
#define PROJECT_DS_BINARYTREE_H

// 二叉树
struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode():val(0), left(nullptr), right(nullptr){};
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode* left, TreeNode* right):val(0), left(left), right(right){};
};

//

#endif //PROJECT_DS_BINARYTREE_H
