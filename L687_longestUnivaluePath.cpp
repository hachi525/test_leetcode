//
// Created by admin on 2022/9/2.
//
#include "DS_binaryTree.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution{
    private:
    int res = 0;
public:
    int dfs(TreeNode* root ){
        if(root == nullptr) return 0;

        int left = 0, right = 0;
        left = dfs(root->left) ;
        right = dfs(root->right) ;
        int left1 = 0, right1 = 0;
        if(root->left && root->val == root->left->val)  left1 = left+1;
        if(root->right && root->val == root->right->val) right1 = right + 1;

        res = max(res, left1+right1);
        return max(left1, right1);
    }

    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

};


int main (){

}