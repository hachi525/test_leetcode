//
// Created by admin on 2022/7/11.
//
#include "MagicDict.h"

    MagicDict:: MagicDict(){
        root = new Trie();
    }

    /** 方法一：《字典树实现》
     * str:当前查询字符串
     * idx:当前下标
     * cnt:修改字符次数*/
    bool MagicDict::backtrack(string& str, Trie* node, int idx, int cnt){
        if(idx == str.size()){
            if(cnt == 1 && node->isEnd == true)
                return true;
            else
                return false;
        }
        for (int i = 0; i < 26; ++i) {//遍历当前next所有字符看是否有相等
            if(node->next[i] == NULL) continue;

            if('a' + i == str[idx]) {
                if (backtrack(str, node->next[i], idx + 1, cnt))
                    return true;
            }
            else if(cnt == 0 && 'a' + i != str[idx]){
                if(backtrack(str, node->next[i], idx+1, cnt+1))
                    return true;
            }
        }
        return false;
    }

    /* 方法一：字典树 */
    void MagicDict::insert(string& str){
        Trie* node = root;
        for(char c:str){
            if(node->next[c-'a'] == NULL)
                node->next[c-'a'] = new Trie();
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }

    /* 方法一：字典树 */
    void MagicDict::buildDict(vector<string> dictionary){
        for(string str:dictionary)
            insert(str);
    }

    /* 方法一：字典树 */
    bool MagicDict::searchWord(string searchWord){
        Trie* node = root;
        return backtrack(searchWord, root, 0, 0);
    }

    /* 方法二：hashmap实现 */
    void MagicDict::buildDict(vector<string> dictionary) {//hashmap存储:字符串长度-字符串
        for(auto& str:dictionary){
            umap[str.size()].push_back(str);
        }
    }

    /* 方法二：hashmap实现 */
    bool MagicDict::searchWord(string searchWord) {
        int n = searchWord.size();
        vector<string> strs = umap[n];  //从hashmap中找字符串长度一致的
        for(string str:strs){//遍历hashmap中所有的字符串str，判断searchWord是否变一次就能成功
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if(str[i] != searchWord[i]) ++cnt;
                if (cnt > 1) break;
                if (i == n-1 && cnt == 1) return true;
            }
        }
        return false;
    }

