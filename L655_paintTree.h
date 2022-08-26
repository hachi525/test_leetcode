//
// Created by admin on 2022/8/22.
//

#ifndef PROJECT_L655_PAINTTREE_H
#define PROJECT_L655_PAINTTREE_H
#ifndef _L655_paintTree_H_
#define _L655_paintTree_H_


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class L655_paintTree {
public:
    int calcHeight(TreeNode* root);
    void dfs(vector<vector<string>>& res, TreeNode* root, int r, int c, const int& height);
    vector<vector<string>> printTree(TreeNode* root);
};


#endif //_L655_paintTree_H_
#endif //PROJECT_L655_PAINTTREE_H
