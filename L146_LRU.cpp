//
// Created by admin on 2022/7/14.
//

#include "L146_LRU.h"
/* 双向链表构造函数 */
DoubleList::DoubleList(){
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
}

/* 从队头插入节点 */
void DoubleList::insert(Node* node){
    node->next = head->next;
    node->prev = head;
    node->next->prev = node;
    head->next = node;
}

/* 移除节点 */
void DoubleList::remove(Node* node){
    node->next->prev = node->prev;
    node->prev->next = node->next;
}

Node* DoubleList::listBack() {
    return tail->prev;
}

void DoubleList::pop_back(){
    remove(tail->prev);
}

/* LRUcache构造函数 */
L146_LRU::L146_LRU(int cap) {
    this->capacity = cap;
    list = new DoubleList();
}

/* 访问cache */
int L146_LRU::get(int key) {
    if(hashMap.find(key) == hashMap.end())
        return -1;
    else{
        Node* node = hashMap[key];
        list->remove(node);
        list->insert(node);
        return node->val;
    }
}

/* 换入 */
void L146_LRU::put(int key, int value) {
    if(hashMap.find(key) != hashMap.end()){//hashmap中有该key
        Node* node = hashMap[key];
        node->val = value;
        list->remove(node);
        list->insert(node);
    }else{//hashmap中没有该key
        if(hashMap.size() == capacity){
            hashMap.erase(list->listBack()->key);
            list->pop_back();
        }
        Node* node = new Node(key, value);
        hashMap.emplace(key, node);
        list->insert(node);
    }

}


int main(){
    L146_LRU* cache = new L146_LRU(2);
    cache->put(1, 1); // 缓存是 {1=1}
    cache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout<< cache->get(1)<<endl;    // 返回 1

    cache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout<< cache->get(2)<<endl;    // 返回 -1 (未找到)
    cache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout<< cache->get(1)<<endl;    // 返回 -1 (未找到)
    cache->get(3);    // 返回 3
    cache->get(4);    // 返回 4
    return 0;
}