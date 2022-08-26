//
// Created by admin on 2022/7/15.
//

#ifndef PROJECT_L558_INTERSECT_H
#define PROJECT_L558_INTERSECT_H

#include <iostream>

using namespace std;
/* 为二位区域构建四叉树：
 * 1.如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null 然后停止。
 * 2.如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值，然后如下图所示，将当前网格划分为四个子网格。
 * 3.使用适当的子网格递归每个子节点。
 * */
// Definition for a QuadTree node.
class Node {
public:
    bool val;       //储存叶子结点所代表的区域的值。1对应True，0对应False；
    bool isLeaf;    //当这个节点是一个叶子结点时为True，如果它有4个子节点则为False 。
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

/* 两个四叉树按位逻辑或运算 */
class L558_intersect {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) ;
};


#endif //PROJECT_L558_INTERSECT_H
