//
// Created by admin on 2022/7/7.
//
#include <iostream>
#include <string>
#include <vector>

#ifndef PROJECT_TRIE_H
#define PROJECT_TRIE_H

using namespace std;

struct treeNode {
    bool isEnd;
    treeNode* next[26];

    treeNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

/* 前缀树||字典树 */
/*
class Trie {
private:
    treeNode* root;

    void __insert(treeNode*& node, string word, int d) {
        if (node == NULL) {
            node = new treeNode();
        }
        if (d == word.length()) {
            node->isEnd = true;
            return;
        }

        __insert(node->next[word[d]], word, d+1);
    }

    treeNode* __search(treeNode* node, string word, int d) {
        if (node == NULL) {
            return NULL;
        }
        if (d == word.length()) {
            return node;
        }
        return __search(node->next[word[d]], word, d+1);
    }

    bool __startWith(treeNode* node) {
        if (node == NULL) {
            return false;
        }
        if (node->isEnd) {
            return true;
        }
        for (int i = 0; i < 26; i++) {
            if (__startWith(node->next[i])) {
                return true;
            }
        }
        return false;
    }

public:
    */
/** Initialize your data structure here. *//*

    Trie() {
        root = new treeNode();
        if (root == NULL) {
            cout << "New treeNode ERROR" << endl;
            return;
        }
    }

    */
/** Inserts a word into the trie. *//*

    void insert(string word) {
        __insert(root, word, 0);
    }

    */
/** Returns if the word is in the trie. *//*

    bool search(string word) {
        treeNode* node = __search(root, word, 0);
        if (node == NULL) {
            return false;
        }
        return node->isEnd;
    }

    */
/** Returns if there is any word in the trie that starts with the given prefix. *//*

    bool startsWith(string prefix) {
        treeNode* node = __search(root, prefix, 0);
        return __startWith(node);
    }
};
*/

//vector<vector<int> > trie(100009, vector<int> (26, 0)); //存储所有的字符串单词

class Trie{
private:
    int N = 100009;
    vector<vector<int> > trie;
    vector<int > count; //类似于isEnd，count[i]记录以i结尾的字符串个数
    int index;  //记录使用了多少个格子
public:
    Trie(){
        vector<int> temp(26, 0);
        trie.resize(N, temp);
    }

    /* 插入新字符串 */
    void insert(string s){
        int p = 0;
        for (int i = 0; i < s.size(); ++i) {
            int u = s[i] - 'a';
            if(trie[p][u] == 0) trie[p][u] = ++index;
            p = trie[p][u];
        }
        count[p]++;
    }

    /* 寻找字符串s */
    bool search(string s){
        int p = 0;
        for (int i = 0; i < s.size(); ++i) {
            int u = s[i] - 'a';
            if(trie[p][u] == 0) return false;
            p = trie[p][u];
        }
        return count[p] != 0;
    }

    /* 判断是否有前缀字符串 */
    bool startsWith(string s){
        int p = 0;
        for (int i = 0; i < s.size(); ++i) {
            int u = s[i] - 'a';
            if(trie[p][u] == 0) return false;
            p = trie[p][u];
        }
        return true;
    }
};

#endif //PROJECT_TRIE_H
