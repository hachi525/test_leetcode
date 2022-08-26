//
// Created by admin on 2022/7/15.
//

#include "L558_intersect.h"
/* 思路：
 * 1、两个叶子结点的合并
 *      isLeaf都为true，根据val值判断：或运算，只有两个都为false时值才为false，否则为true
 * 2、一个叶子结点node1，一个非叶子结点node2：
 *      当非叶子结点node2的子结点值不全相同（true|false）时，为叶子结点node1创建4个子结点，值与node1.val相同
 *      node1.val==true ? return node1
 *      node1.val==false ? 看node2的子结点的值，值为true返回true，false时（两个都是false）也可以返回false
 * 3、两个非叶子结点的合并
 *      isleaf = false;
 *      子结点合并：
 * */

Node *L558_intersect::intersect(Node *quadTree1, Node *quadTree2) {
    // 两个都为叶子结点
    if (quadTree1->isLeaf && quadTree2->isLeaf){
        if (quadTree1->val) return quadTree1;
        else if (quadTree2->val)    return quadTree2;
        else    return quadTree1;
    }
    Node* resT = new Node();    // 结果四叉树
    resT->topLeft = intersect(quadTree1->isLeaf?quadTree1:quadTree1->topLeft, quadTree2->isLeaf?quadTree2:quadTree2->topLeft);
    resT->topRight = intersect(quadTree1->isLeaf?quadTree1:quadTree1->topRight, quadTree2->isLeaf?quadTree2:quadTree2->topRight);
    resT->bottomLeft = intersect(quadTree1->isLeaf?quadTree1:quadTree1->bottomLeft, quadTree2->isLeaf?quadTree2:quadTree2->bottomLeft);
    resT->bottomRight = intersect(quadTree1->isLeaf?quadTree1:quadTree1->bottomRight, quadTree2->isLeaf?quadTree2:quadTree2->bottomRight);

    bool a = resT->topLeft->isLeaf && resT->bottomLeft->isLeaf && resT->topRight->isLeaf && resT->bottomRight->isLeaf;  // 所有子结点为叶子节点时为true
    bool b = resT->topLeft->val && resT->topRight->val && resT->bottomLeft->val && resT->bottomRight->val;  // 所有子结点的val都true时为true
    bool c = resT->topLeft->val || resT->topRight->val || resT->bottomLeft->val || resT->bottomRight->val;  // 只有所有子结点的val都false时才为false

    resT->isLeaf = a && (b || !c);   // 更新resT是否为叶子结点,!c:子结点val不全相同时c为真，即!c为假；只有子结点都是叶子结点，且子结点的val都为1或都为0时，isLeaf为真
    resT->val = resT->topLeft->val; // 更新resT的值，随便赋值
    if(resT->isLeaf)    //如果是叶子结点，给子结点赋null
        resT->topLeft = resT->topRight = resT->bottomLeft = resT->bottomRight = nullptr;
    return resT;
}

void Test(){
    Node *quadTree1, *quadTree2;
    L558_intersect solution;
    solution.intersect(quadTree1, quadTree2);
}

int main(){
    Test();
    return 0;
}