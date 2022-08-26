//
// Created by admin on 2022/7/14.
//

#include "L_460LFU.h"
/* 方法一： 哈希表+双向链表
 * 时间复杂度：get 时间复杂度 O(1)O(1)，put 时间复杂度 O(1)O(1)
 * 空间复杂度：O(capacity)
 * */
/* 用数据结构的容量capacity 初始化对象 */
L_460LFU::L_460LFU(int _capacity) {
    capacity= _capacity;
    minFreq = 0;    // 用于删除最小频率的链表中的缓存节点
    key_listMap.clear();
    freq_listMap.clear();
}

/* 如果键key存在于缓存中，则获取键的值，否则返回-1 */
int L_460LFU::get(int key) {
    if(capacity == 0)    return -1;
    if(key_listMap.find(key) == key_listMap.end())  return -1;
    Node* node = key_listMap[key];
    int freq = node->freq;
    // 频率+1，从freq+1链表中更新位置
    freq_listMap[freq]->remove(node);
    if(freq_listMap[freq]->size() == 0){//如果删除结点后链表为空，删除哈希表中对应键值对，并更新minFreq
        freq_listMap.erase(freq);
        if (minFreq == freq) minFreq += 1;
    }
    ++ node->freq;
    if(freq_listMap.find(node->freq) == freq_listMap.end()){
        freq_listMap[node->freq] = new FreqList();
    }
    freq_listMap[node->freq]->insert(node);
    key_listMap[key] = node;
    return node->val;
}

void L_460LFU::put(int key, int value) {
    if (capacity == 0) return ;
    if(key_listMap.find(key) == key_listMap.end()){ // 缓存中没有该对应结点 key-value
        if (key_listMap.size() == capacity){    //缓存已满，从最小频率链表里删一个最早没用的
            key_listMap.erase(freq_listMap[minFreq]->back()->key);  // key_listMap更新
            freq_listMap[minFreq]->pop_back();
            if (freq_listMap[minFreq]->size() == 0) //key_listMap更新，如果删除后，最小频率链表空了，在哈希表中删除minFreq对应的键值对
                freq_listMap.erase(minFreq);
        }
        Node* node = new Node(key, value);
        // 更新两个哈希表
        if(freq_listMap.find(1) == freq_listMap.end()){
            freq_listMap[1] = new FreqList();
        }
        freq_listMap[1]->insert(node);  //key_listMap更新
        key_listMap[key] = node;    //key_listMap更新
        minFreq = 1;    //更新minFreq
    } else{ // 缓存中已有该对应结点 key-value
        Node* node = key_listMap[key];
        int freq = node->freq;
        freq_listMap[freq]->remove(node);
        if(freq_listMap[freq]->size() == 0 ){   //如果删除结点后链表为空，删除哈希表中对应键值对，并更新minFreq
            freq_listMap.erase(freq);
            if(minFreq == freq)     minFreq += 1;
        }
        node->val = value;//更新值
        node->freq ++;
        if( freq_listMap.find(node->freq)== freq_listMap.end()){
            freq_listMap[node->freq] = new FreqList();
        }
        freq_listMap[node->freq]->insert(node);
        key_listMap[key] = node;
    }
}

int main(){
    int capacity = 2;
//    cin >> capacity;
    L_460LFU* lfu = new L_460LFU(capacity);

    lfu->put(2, 1);   // cache=[2,_], cnt(2)=1
    lfu->put(2, 2);   // cache=[2,_], cnt(2)=1
    cout<< lfu->get(2) << endl;      // 返回2 cnt(2)=2
    lfu->put(1, 1);   // cache=[2,1], cnt(1)=1 cnt(2)=2
    lfu->put(4, 1);   // cache=[4,2], cnt(4)=1 cnt(2)=3
    cout<< lfu->get(2) << endl;      // 返回2
    return 0;
}