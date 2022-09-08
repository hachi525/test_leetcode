//
// Created by admin on 2022/9/7.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// 迪杰斯特拉dijstra
// dp似乎不能做
class Solution{
private:
    bool direction; //0-水平，1-垂直
public:
    int soldier(vector<vector<char >> street){
        int m = street.size(), n = street[0].size();    // m行n列
        vector<vector<int> > dp;
        pair<int, int> S;
        pair<int, int> E;
        for(int i=0;i<street.size();i++){
            if(find(street[i].begin(),street[i].end(),'S')!=street[i].end())
                ;
            if(find(street[i].begin(),street[i].end(),'S')!=street[i].end())
                ;
        }
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(street[i][j] == 'E'){

                }else if(street[i][j] == 'S'){

                }


            }
        }


        return dp[][];
    }

};

int main(){
    Solution solution;
    vector<vector<char> > street;
    solution.soldier(street)
    return 0;
}