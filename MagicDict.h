//
// Created by admin on 2022/7/11.
//
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#ifndef PROJECT_MAGICDICT_H
#define PROJECT_MAGICDICT_H

struct Trie{// 字典树结构体
    bool isEnd;
    Trie* next[26];
    Trie(){
        isEnd = false;
    }
};
/*
 * struct Trie {
    bool isEnd;
    vector<Trie*> children;
    Trie() : isEnd(false), children(26, NULL) {}
    ~Trie() {
        for (Trie* child : children) {
            if (child) delete child;
        }
    }

};
*/
class MagicDict {
private:
    Trie* root;
    unordered_map<int, vector<string> > umap;
public:
    MagicDict();
    /**
     * str:当前查询字符串
     * idx:当前下标
     * cnt:修改字符次数*/
    bool backtrack(string& str, Trie* node, int idx, int cnt);

    void insert(string& str);

    void buildDict(vector<string> dictionary);

    bool searchWord(string searchWord);
};


#endif //PROJECT_MAGICDICT_H
