//
// Created by admin on 2022/7/14.
//

#include "L745_wordFilter.h"

void Trie::insert(const string& word, int idx) {
    Trie* node = this;
    for (char c:word) {
        if(node->next[c-'a'] == NULL)  {
            node->next[c-'a'] = new Trie();
        }
        node = node->next[c-'a'];
        node->idx.push_back(idx);
    }
    node->isEnd = true;
}

vector<int> Trie::search(string word, bool isTurn) {
    if(isTurn)
        reverse(word.begin(),word.end());
    Trie* node = this;
    for (char c:word) {
        node = node->next[c-'a'];
        if(node == NULL) {
            return {};
        }
    }
    return node->idx;
}

/* 使用后缀+'#'+前缀结构构造字符串插入前缀树中 */
void Trie::insert1(string word, int idx) {
    Trie* node = this;
    for (char c:word) {
        int t = c=='#'?26:c-'a';
        if(!node->next[t]) {
            node->next[t] = new Trie();
            node->next[t]->index = idx;
        }
        node = node->next[t];
        node->index = idx;
    }
}
/* 在使用后缀+'#'+前缀结构构造字符串的前缀树中查找字符串 */
int Trie::search1(string word) {
    Trie* node = this;
    for (char c:word) {
        int t = c=='#'?26:c-'a';
        if (!node->next[t]) return -1;
        node = node->next[t];
    }
    return node->index;
}

/* 方法一：建前缀和后缀两棵树会超时
 * 方法二：将所有可能的后缀+”#“+单词本身插入树中
 *      插入单词words[i]时，将所有可能的后缀+分界符+words[i]单词本身的形式插入字典树
 *      这样在查找前缀prefix和后缀suffix时，可以组合成单词：suffix+分界符+preffix来查找
*/
L745_wordFilter::L745_wordFilter(vector<string> &words) {
    /* 方法一：两棵树查询结果求交集 */
    prefTrie = new Trie();
    suffTrie = new Trie();
    for (int i = 0; i < words.size(); i ++) {
        prefTrie->insert(words[i], i);
        reverse(words[i].begin(), words[i].end());
        suffTrie->insert(words[i], i);
    }

    /* 方法二： 后缀 + # + 字符串 */
    for (int i = 0; i < words.size(); ++i) {
        string temps = "#" + words[i];
        suffPrefTrie->insert1(temps, i);
        for (int j = words[i].size()-1; j >= 0; --j) {
            temps = words[i][j] + temps;
            suffPrefTrie->insert1(temps, i);
        }
    }
}

int L745_wordFilter::f(string pref, string suff) {
    /* 方法一：两棵树查询结果求交集 */
    bool isTurn = false;
    vector<int> prefixs = prefTrie->search(pref, false);
    vector<int> suffixs = suffTrie->search(suff, true);
    if(prefixs.size() == 0 || suffixs.size() == 0 )
        return -1;

    int i = prefixs.size()-1, j = suffixs.size()-1;
    while (i >= 0 && j >= 0){
        if (prefixs[i] == suffixs[j])
            return prefixs[i];
        else if(prefixs[i] > suffixs[j])
            i --;
        else
            j --;
    }
    return -1;

    /* 方法二： 后缀 + # + 字符串 */
    return suffPrefTrie->search1(suff+'#'+pref);

}


int main(){
    vector<vector<string>> wordsList;
    // 输入数组
    cout << "输入数组" << endl;
    vector<string> words;
    string temp;
    for (int i = 0; i < 2; ++i) {
        cin >> temp;
        words.push_back(temp);
    }
    string pref, suff;
    //获取 words/pref/suff
    cout << "输入前缀 后缀" << endl;
    cin >> pref >> suff;
    L745_wordFilter wordFilter(words);
    wordFilter.f(pref, suff);
    cout << wordFilter.f(pref, suff) << endl;
    return 0;
}