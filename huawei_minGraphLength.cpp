//
// Created by admin on 2022/8/24.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class minGL{
private:
    int count;
//    unordered_set<int> townSet; // 遍历过的小镇集合
public:
    // dfs找到起点start到终点end间的路径数目
    void dfs(vector< vector<int>>& graph, int start, int end){
        if(start == end){
            count ++;
            return;
        }
        for(auto& neighbor: graph[start]){
            dfs(graph, start, end);
        }
    }

    int getMinGL(){
        int n;
        vector<vector<int> > graph(n, vector<int>(0, n));  //邻接矩阵
/* 1. 遍历判断是否联通
 * 2. 随机选择一个点作为起点
 * 3. 从该点进行深度遍历，能前进就不要后退
 * 4.
 * */
        cin >> n;   //小镇个数
        for(int i= 0; i < n; i++){
            vector<int> town(0);
            int number = 0;
            while(cin >> number){
                graph[0][number - 1] = 1;
                graph[number - 1][0] = 1;

                if(cin.get() == '\n')
                    break;
            }

        }
        int res = 0, count; // 路径长度||小镇数量
        for(int i = 0; i < n; i ++){
            count = 0;
            for(int j = 0; j < n; j ++){

            }

        }
        if(count != n)
            return -1;
        return res;
    }

};

int main(){
    minGL solve;
    solve.getMinGL();
    return 0;
}