//
// Created by admin on 2022/7/19.
//

#include "L731_MyCalendarTwo.h"

L731_MyCalendarTwo::L731_MyCalendarTwo() {

}

/* 方法一： 两个数组，直接记录交叉区间
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 * */
bool L731_MyCalendarTwo::book(int start, int end) {
    for (auto& [l, r]: overlaped) {//有无交叉的三重预订
        if(l < end && start < r)
            return false;
    }

    for (auto& [l, r]:booked) {//交叉的二重预定
        if (l < end && start < r)
            overlaped.emplace_back(max(start, l), min(end, r));
    }
    booked.emplace_back(start, end);
    return true;
}

/* 方法二：差分数组思想
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 * */
bool L731_MyCalendarTwo::book1(int start, int end) {
    int maxBook = 0;
    cnt[start]++;   // 从start到末尾全部+1
    cnt[end]--;     // 从end到末尾全部-1
    // 上面两句合起来就是[start, end)全部+1
    for (auto &[_, freq] : cnt) {
        maxBook += freq;    // 预订次数
        if (maxBook > 2) {  //如果这次预订以后，到三重预订了，恢复状态，并且返回false
            cnt[start]--;
            cnt[end]++;
            return false;
        }
    }
    return true;
}

/* 方法三：线段树，区间和
 * 时间复杂度：O(nlogC),每次查询节点数最大为树的深度度logC，C固定1e9，n为预订数
 * 空间复杂度：O(nlogC),每次预订会在线段树上增加logC个节点
 * 可以动态开点（估点/指针）将C由1e9转变为查询数
 * */
bool L731_MyCalendarTwo::book2(int start, int end) {
    //1.建树
    //2.查询树中区间和，大于2时返回false
    //3.更新标记
}

void Test(){
    int start, end;
    L731_MyCalendarTwo* cal = new L731_MyCalendarTwo();
    cal->book(start, end);

}

int main() {
    Test();
    return 0;
}
