//
// Created by admin on 2022/8/27.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
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

using ULL = unsigned long long;
class Solution{

public:
    int widthOfBinaryTree(TreeNode* root){
        unordered_map<int, ULL> levelMin;
        function<ULL(TreeNode*, int, ULL)> dfs = [&](TreeNode* node, int depth, ULL index)->ULL{
            if (node == nullptr) {
                return 0LL;
            }
            if (!levelMin.count(depth)) {
                levelMin[depth] = index; // 每一层最先访问到的节点会是最左边的节点，即每一层编号的最小值
            }
            return max({index - levelMin[depth] + 1LL,
                        dfs(node->left, depth + 1, index * 2),
                        dfs(node->right, depth + 1, index * 2 + 1)});
        };

        return dfs(root, 1, 1LL);
    }
};

