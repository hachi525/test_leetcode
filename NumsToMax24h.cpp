//
// Created by admin on 2022/9/21.
//

#include <bits/stdc++.h>
#include <string>

using namespace std;
// 6位数字组成的最大24进制时间
int findMax(vector<int>& arr, int limit){
    if(arr.empty()){
        return -1;
    }
    int res = -1;
    for(auto& num : arr)
        if(num < limit) res = max(res, num);
    for(int i = 0; i < arr.size(); i++)
        if(arr[i] == res)   arr[i] = -1;
    return res;
}

string largestTimeFormDigits(vector<int>& arr){
    if(arr.size() < 6)
        return "";
    // 方法一：从高到底一位一位计算
    int hh = -1, hl = -1;
    int mh = -1, ml = -1;
    int sh = -1, sl = -1;

    hh = findMax(arr, 3);
    if(hh == 2) hl = findMax(arr, 5);
    else    hl = findMax(arr, 10);

    mh = findMax(arr, 6);
    ml = findMax(arr, 10);

    sh = findMax(arr, 6);
    sl = findMax(arr, 10);

    if(hh == -1 && hl == -1 && mh == -1 && ml == -1 && sh == -1 && sl == -1)
        return "";
    return to_string(hh) + to_string(hl) + ":" + to_string(mh)+ to_string(ml) + ":" +  to_string(sh)+ to_string(sl);


    // 方法二：
    // 统计数字频率
    unordered_map<int, int> map;
    for(auto& num : arr){
        map[num] ++;
    }

    // 特殊情况
    if(map.find(2)!= map.end() && map[2] == 1 &&
       map.find(4) != map.end() && map[4] == 1 &&
       map.find(0) != map.end() && map[0] == 4){
        return "24:00:00";
    }
    int cnt = 3;
    while(cnt != 0){

    }

}

class A{
public:
    A() {};
    A(const char* str) : _str(str){};

    ~A(){};


public:
    string _str;
};




/* 9.21联想笔试第二题 抢红包排序：金额大优先，相同时按先后顺序 */
struct cmp{
    bool operator()(const vector<string>& a, const vector<string>& b){
        return stoi(a[1]) == stoi(b[1]) ? stoi(a[2]) < stoi((b[2])): stoi(a[1]) > stoi(b[1]);
    }
};
void test(){
    int n , timestamp = 0;
    cin >> n;
    vector<vector<string>> vec;
    string line;
    getline(cin, line);
    while(getline(cin, line)){
        stringstream ss(line);
        string word;
        vector<string> temp;
        while(ss >> word){
            temp.emplace_back(word);
        }
        temp.emplace_back(to_string(timestamp));
        vec.emplace_back(temp);
        if(timestamp == n-1) break;
        timestamp ++;
    }
    stable_sort(vec.begin(), vec.end(), [](const vector<string>& a, const vector<string>& b){
        return stoi(a[1]) == stoi(b[1]) ? stoi(a[2]) < stoi((b[2])): stoi(a[1]) > stoi(b[1]);
    });
//    stable_sort(vec.begin(), vec.end(), cmp());
    for(auto& id : vec){
        cout << id[0] << endl;
    }
}

/* 单链表排序——奇数位置在前，偶数位置在后 */
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(nullptr) {}
//};
//
//ListNode* sortList(ListNode*  Node){
//    if(Node == nullptr || Node->next == nullptr || Node->next->next == nullptr)    return Node;
//    ListNode* OddHead = Node;
//    ListNode* EvenHead = Node->next;
//    ListNode* even;
//        while(even != nullptr && even->next != nullptr){
//        OddHead->next = OddHead->next->next;
//        even->next = even->next->next;
//        OddHead = OddHead->next;
//        even = even->next;
//    }
//    OddHead->next = EvenHead;
//    return Node;
//}


int main(){
    test();
}