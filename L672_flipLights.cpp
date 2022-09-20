//
// Created by admin on 2022/9/15.
//
#include <bits/stdc++.h>

using namespace std;

// 1...n
// 1:all reverse
// 2:even reverse
// 3:odd reverse
// 4:3k+1 reverse 1,4,7,10,13,16

class Solution {
public:
    int flipLights(int n, int presses){
        if(presses == 0)
            return 1;
        if(n == 1)
            return 2;
        if(n == 2)
            return presses == 1 ? 3 : 4;
        return presses == 1 ? 4 :( presses == 2 ? 7 : 8);
    }
};

int main(){
    Solution solution;
    solution.flipLights(3,3);
    return 0;
}