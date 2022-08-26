//
// Created by admin on 2022/7/14.
//

#ifndef PROJECT_L_460LFU_H
#define PROJECT_L_460LFU_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
/* Hard
 * 实现 LFUCache-Least Frequency Use类：
 * 1.LFUCache(int capacity) - 用数据结构的容量capacity 初始化对象
 * 2.int get(int key)- 如果键key 存在于缓存中，则获取键的值，否则返回 -1
 * 3.void put(int key, int value)- 如果键key 已存在，则变更其值；如果键不存在，请插入键值对。
 * 当缓存达到其容量capacity 时，则应该在插入新项之前，移除最不经常使用的项。
 * 移除时当存在平局（即两个或更多个键具有相同使用频率）时，应该去除最近最久未使用的键。
 *
 * 为了确定最不常使用的键，可以为缓存中的每个键维护一个使用计数器。使用计数最小的键是最久未使用的键。    ——哈希表
 * 当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。
 * 对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。*/
using namespace std;

/* 双向链表节点 */
struct Node{
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;
    Node():key(-1), val(-1), freq(0), prev(nullptr), next(nullptr){}
    Node(int _k, int _v):key(_k), val(_v), freq(1), prev(nullptr), next(nullptr){}
};

/* 双向链表结构体 */
struct FreqList{
    Node *head, *tail;
    int _size = 0;
    FreqList(){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty(){
        return  head->next == tail && tail->prev == head;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
        _size ++;
    }
    void remove(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        _size --;
    }

    Node* back() {
        return tail->prev;
    }

    void pop_back() {
        if(!isEmpty()) {
            remove(tail->prev);
        }
    }

    int size(){
        return _size;
    }
};

/* 解题思路：
 * 方法一：哈希表+哈希表+双向链表*2
 * 方法二：平衡二叉树+哈希表
 * */
class L_460LFU {
private:
    int capacity, minFreq;
    unordered_map<int, Node*> key_listMap;      // key-FreqList
    unordered_map<int, FreqList*> freq_listMap;     // freq-FreqList
/*  STL容器中的list序列式容器，双向链表
    unordered_map<int, list<Node*> > key_listMap;   // 按照频率大小排序
    unordered_map<int, list<Node*> > freq_listMap;  // 频率为freq的缓存节点Node链表，同一个链表中按时间顺序排序
*/
public:
    L_460LFU(int _capacity);
    int get(int key);
    void put(int key, int value);
};


#endif //PROJECT_L_460LFU_H
