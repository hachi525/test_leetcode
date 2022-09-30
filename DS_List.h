//
// Created by admin on 2022/9/23.
//

#ifndef PROJECT_DS_LIST_H
#define PROJECT_DS_LIST_H

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr){}
    ListNode(int _val):val(_val), next(nullptr){}
    ListNode(int _val, ListNode* node):val(_val), next(node){}
};

/* LC-707， index取值从0开始，val取值范围为[0, 1000] */
class MyLinkedList {
private:
    int size = 0;
    ListNode* head = new ListNode();

public:
    MyLinkedList() {

    }

    int get(int index) {
        if(index < 0 || index > size-1)    return -1;
        ListNode* node = head->next;
        while(index --){
            node = node->next;
        }
        return node->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if(index > size)    return ;
        ListNode* node = head;
        ListNode* temp = new ListNode(val, nullptr);

        if(index <= 0){//头插
            node = node->next;
            head->next = temp;
            temp->next = node;
        }else if(index == size){//尾插
            while(node->next){
                node = node->next;
            }
            node->next = temp;
            temp->next = nullptr;
        }else{//中间插
            while(index --){
                node = node->next;
            }
            ListNode* curNode = node;
            node = node->next;
            curNode->next = temp;
            temp->next = node;
        }
        size ++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)  return ;
        ListNode* node = head;
        while(index -- > 0){
            node = node->next;
        }
        ListNode* temp = node->next;
        node->next = temp->next;
        temp->next = nullptr;
        delete temp;
        size --;
    }
};

#endif //PROJECT_DS_LIST_H
