//
// Created by admin on 2022/8/22.
//

#include "L655_paintTree.h"


int L655_paintTree::calcHeight(TreeNode *root) {
    int h=0;
    if(root->left)
        h = max(h, calcHeight(root->left)+1);
    if(root->right)
        h = max(h, calcHeight(root->right)+1);
    return h;
}

void L655_paintTree::dfs(vector<vector<string>> &res, TreeNode *root, int r, int c, const int &height) {
    res[r][c] = to_string(root->val);
    if(root->left)
        dfs(res, root->left, r+1, c-(1<<(height-r-1)), height);
    if(root->right)
        dfs(res, root->right, r+1, c+(1<<(height-r-1)), height);
}

vector<vector<string>> L655_paintTree::printTree(TreeNode *root) {
    int height = calcHeight(root);
    int m = height + 1, n = (1<<(height+1))-1;
    vector<vector<string> > res(m, vector<string>(n, ""));
    dfs(res, root, 0, (n-1)/2, height);
    return res;
}

int main() {

    return 0;
}

