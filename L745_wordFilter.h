//
// Created by admin on 2022/7/14.
//

#ifndef PROJECT_L745_WORDFILTER_H
#define PROJECT_L745_WORDFILTER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

class Trie{
private:
    bool isEnd;
    Trie* next[27];
    vector<int> idx;    //建前缀树和后缀树两棵树时使用
    int index;          //后缀+'#'+前缀
public:
    Trie(){
        isEnd = false;
        for(int i = 0; i < 27; i ++){
            next[i] = NULL;
        }
        index = -1;
    }
    /* 方法一：两棵树 */
    void insert(const string& word, int idx);
    vector<int> search(string word, bool isTurn);

    /* 方法二：一棵树（后缀+'#'+前缀） */
    void insert1(string word, int idx);
    int search1(string word);
};

class L745_wordFilter {
    /* 方法一：两棵树查询结果求交集 */
    Trie* prefTrie; //前缀树
    Trie* suffTrie; //后缀树
    /* 方法二： 后缀 + # + 字符串 */
    Trie* suffPrefTrie = new Trie();
public:
    L745_wordFilter(vector<string>& words);

    /* 返回词典中具有前缀 prefix 和后缀 suff 的单词的下标。
     * 如果存在不止一个满足要求的下标，返回其中 最大的下标 。如果不存在这样的单词，返回 -1
    */
    int f(string pref, string suff);
};



#endif //PROJECT_L745_WORDFILTER_H
