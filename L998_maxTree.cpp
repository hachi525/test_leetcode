//
// Created by admin on 2022/8/30.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "DS_binaryTree.h"

using namespace std;

/* 建树的思路：单调栈
 * 1.如果当前元素小于栈顶元素：入栈
 * 2.如果当前元素大于栈顶元素：
 *  · 栈中只有一个元素，栈顶元素作为当前元素的左子节点
 *  · 栈中有多个元素，循环将栈顶元素作为下一个元素的右子节点
 *  3.结束建树
 *
 *  如果要在原数组后加一个元素a，需要在原先的树上直接进行修改而不是重新建树
 *  那么：
 *      1) 如果a大于根节点的值，那么将a作为根节点，并将原先的树作为a的左子树
 *      2) 如果a小于根节点的值，那么找到根节点的右子节点，重复1)进行判断
 * */


class Solution{
public:
    TreeNode* constructMaximumBinaryTree(vector<int >& nums){
        vector<TreeNode*> stk;
        for(int i = 0; i < nums.size(); i ++){
            TreeNode* node = new TreeNode(nums[i]);
            while(!stk.empty()){
                if(node->val > stk.back()->val){
                    node->left = stk.back();
                    stk.pop_back();
                } else if(node->val < stk.back()->val){
                    stk.back()->right = node;
                    stk.push_back(node);
                    break;
                }
            }
            if(stk.empty()){
                stk.push_back(node);
            }
        }
        // 方法二：
        // vector<int> st;
        // vector<TreeNode*> tree(n);
        // for(int i = 0; i < n; i ++){
        //     tree[i] = new TreeNode(nums[i]);
        //     while(!st.empty() && nums[i] > nums[st.back()]){
        //         tree[i]->left = tree[st.back()];
        //         st.pop_back();
        //     }
        //     if(!st.empty()){
        //         tree[st.back()]->right = tree[i];
        //     }
        //     st.push_back(i);
        // }

        return stk[0];
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val){
        /* 非递归解法 */
        TreeNode* parent = nullptr;
        TreeNode* cur = root;
        while(cur){
            if(val > cur->val){
                if(!parent)
                    return new TreeNode(val, root, nullptr);
                TreeNode* node = new TreeNode(val, cur, nullptr);
                root->right = node;
                return root;
            }else{
                parent = cur;
                cur = cur->right;
            }
        }
        parent->right = new TreeNode(val);
        return root;


        /* 递归解法 */
        if(!root || root->val < val)
            return new TreeNode(val, root, nullptr);
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};


int main (){
    Solution solution;
    vector<int> nums;
    // 构建树，并返回根节点
    TreeNode* root = solution.constructMaximumBinaryTree(nums);
    int val;
    // 在nums后添加元素val，在原有树的基础上直接添加该节点
    solution.insertIntoMaxTree(root, val);
    return 0;
}