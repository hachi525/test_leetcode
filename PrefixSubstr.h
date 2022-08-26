//
// Created by admin on 2022/7/8.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#ifndef PROJECT_PREFIXSUBSTR_H
#define PROJECT_PREFIXSUBSTR_H

/** L.2255
 * 给你一个字符串数组words和一个字符串s，其中words[i] 和s只包含 小写英文字母。
 * 请你返回 words中是字符串 s前缀的 字符串数目。
 * 一个字符串的 前缀是出现在字符串开头的子字符串。子字符串是一个字符串中的连续一段字符序列。
 * */

class PrefixSubstr {
public:
    int countPrefixes(vector<string>& words, string s){
        int res = 0;
        auto isPrefix = [&](const string&word)->bool{
            if(s.size() < word.size())
                return false;
            for (int i = 0; i < word.size(); ++i) {
                if(word[i] != s[i])
                    return false;
            }
            return true;
        };

        for(const string& word:words){
            if(isPrefix(word)){
                res ++;
            }
        }
        return res;
    }
};

/**
class PrefixSubstr{
public:
    int countPrefixes(vector<string>& words, string s){
        int res = 0;
        for(auto& word:words){
            if(s.substr(0, word.size()) == word)
                res ++;
        }
        return res;
    }
};
*/


#endif //PROJECT_PREFIXSUBSTR_H
