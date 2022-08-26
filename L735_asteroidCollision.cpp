//
// Created by admin on 2022/7/13.
//

#include "L735_asteroidCollision.h"

/*
 * 给定一个整数数组 asteroids，表示在同一行的行星。
 * 对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。
 * 每一颗行星以相同的速度移动。找出碰撞后剩下的所有行星。
 * 碰撞规则：
 * 两个行星相互碰撞，较小的行星会爆炸。
 * 如果两颗行星大小相同，则两颗行星都会爆炸。
 * 两颗移动方向相同的行星，永远不会发生碰撞。
*/

/* 栈模拟 */
vector<int> L735_asteroidCollision::asteroidCollision(vector<int> &asteroids) {
    vector<int> st;   //模拟栈
    for (auto aster:asteroids) {
        bool alive = true;  //alive:aster和栈顶的小行星相撞后是否还能存活
        while (alive && aster<0 && !st.empty() && st.back() > 0){//只有栈顶（左侧的小行星）向右，aster（右侧的小行星）向左，才有碰撞的判断
            alive = st.back() < -aster;    //aster大才能存活，否则直接去世
            if (st.back() <= -aster)
                st.pop_back();  //aster大的话就把栈顶的小行星出栈
        }
        if(alive)    st.push_back(aster);
    }
    return st;
}

int main(){
    vector<int> asteroids;
    /* 输入asteroids数组 */
    L735_asteroidCollision solution;
    solution.asteroidCollision(asteroids);
    /* 输出数组 */
    return 0;
}
