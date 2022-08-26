//
// Created by admin on 2022/7/18.
//

#include "L427_construct4Tree.h"

/* 方法一： 暴力递归
 * 时间复杂度：O(n^2+logn∗n^2)
 * 空间复杂度：O(1)
 * */
Node* L427_construct4Tree::construct(vector<vector<int>> &grid) {
    g = grid;
    int n = grid.size();
    return dfs(0, 0, n-1, n-1);
}

/* 递归对以(a,b)为左顶点，(c,d)为右底点的矩阵建立四叉树*/
Node *L427_construct4Tree::dfs(int a, int b, int c, int d) {
    bool isSame = true; //矩阵中值是否都相同
    int t = g[a][b];
    for (int i = a; i <= c && isSame; ++i) {
        for (int j = b; j <= d && isSame; ++j) {
            if (g[i][j] != t) isSame = false;
        }
    }
    if(isSame)
        return new Node(t==1, true);

    Node* root = new Node(t==1, false);
    int dx = c-a+1, dy = d-b+1;
    root->topLeft = dfs(a, b, a+dx/2-1, b+dy/2-1);
    root->topRight = dfs(a, b+dy/2, a+dx/2-1 , d);
    root->bottomLeft = dfs(a+dx/2, b, c, b+dy/2-1);
    root->bottomRight = dfs(a+dx/2, b+dy/2, c, d);
    return root;
}

/* 方法二：优化 前缀和+递归 */
Node *L427_construct4Tree::construct1(vector<vector<int>> &grid) {
    g = grid;
    int n = grid.size();
    vector<vector<int> > temp(n+1);
    for(int i = 0; i <= n; i ++){
        temp[i].resize(n+1);
    }
    sum = temp;
    // for(int i = 0; i <= n; i ++){
    //     vector<int> temp(n+1);
    //     sum.push_back(temp);
    // }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] + grid[i-1][j-1] - sum[i-1][j-1];
        }
    }
    return dfs(0, 0, n-1, n-1);
}

Node *L427_construct4Tree::dfs1(int a, int b, int c, int d) {
    int cur = sum[c+1][d+1] - sum[a][d + 1] - sum[c+1][b] + sum[a][b];
    int dx = c-a+1, dy = d-b+1, num = dx*dy;
    if(cur == 0 || cur == num)
        return new Node(g[a][b]==1, true);
    Node* root = new Node(g[a][b]==1, false);
    root->topLeft = dfs(a, b, a+dx/2-1, b+dy/2-1);
    root->topRight = dfs(a, b+dy/2, a+dx/2-1 , d);
    root->bottomLeft = dfs(a+dx/2, b, c, b+dy/2-1);
    root->bottomRight = dfs(a+dx/2, b+dy/2, c, d);
    return root;
}

/* 写个层次遍历输出四叉树的方法 */
void printLayer(Node* root){

}

void Test(){
    int n;
    cin >> n;
    vector<vector<int> > grid(n, vector<int>(n));
    // 输入n*n矩阵
    L427_construct4Tree* solution = new L427_construct4Tree();
    solution->construct(grid);
}


int main(){
    Test();
    return 0;
}