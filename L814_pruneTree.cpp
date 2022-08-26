//
// Created by admin on 2022/7/21.
//

#include "L814_pruneTree.h"

/* 题述：二叉树的每个结点的值要么是 0 ，要么是 1 。
 * 返回移除了所有不包含 1 的子树的原二叉树。
 * 节点 node 的子树为 node 本身加上所有 node 的后代。
 * */
TreeNode *L814_pruneTree::pruneTree(TreeNode *root) {
    if(root == nullptr) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left != nullptr || root->right != nullptr)    return root;
    return root->val == 0? nullptr:root;
    /* if(!root->left && !root->right && !right->val) return root;*/
}

TreeNode* Test(){
    TreeNode* root;
    L814_pruneTree* solution = new L814_pruneTree;
    return solution->pruneTree(root);
}

int main() {
    Test();
    return 0;
}
