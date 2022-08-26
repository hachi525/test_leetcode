//
// Created by admin on 2022/7/14.
//

#ifndef PROJECT_L146_LRU_H
#define PROJECT_L146_LRU_H

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

/*双向链表结点*/
struct Node{
    int key, val;
    Node *next, *prev;
    Node(int k, int v):key(k), val(v), prev(nullptr), next(nullptr){}
};

class DoubleList{
private:
    Node *head, *tail;
public:
    DoubleList();
    void insert(Node* node);
    void remove(Node* node);
    Node* listBack();
    void pop_back();
};

class L146_LRU {
private:
    int capacity;
    unordered_map<int, Node*> hashMap;
    DoubleList* list;

public:
    L146_LRU(int capacity);
    int get(int key);
    void put(int key, int value);
};


#endif //PROJECT_L146_LRU_H
