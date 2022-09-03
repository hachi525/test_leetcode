//
// Created by admin on 2022/9/2.
//


#include "DS_binaryTree.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution{
private:
    int maxSum = INT_MAX;
public:
    int maxChildSum(TreeNode* node){
        if(node == nullptr) return 0;

        int leftSum = max(maxChildSum(node->left), 0);
        int rightSum = max(maxChildSum(node->right), 0);
        int priceNewPath = node->val + leftSum + rightSum;

        maxSum = max(priceNewPath, maxSum);
        return node->val + max(leftSum , rightSum);
    }

    int maxPathSum(TreeNode* root){
        maxChildSum(root);
        return maxSum;
    }
};

int main(){
    Solution* solution = new Solution();
    TreeNode *root;
    solution->maxPathSum(root);
}

