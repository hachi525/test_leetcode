//
// Created by admin on 2022/9/1.
//
#include <queue>
#include <string>
#include <iostream>

using namespace std;

// 大顶堆
struct cmp_max{
    bool operator ()(pair<int, string>& a, pair<int, string>& b){
        if(a.first == b.first)  return a.second > b.second;
        return a.first < b.first;
    }
};

// 小顶堆
struct cmp_min{
    bool operator() (pair<int, string>& a, pair<int, string>& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

class SORTracker{
private:
    int queryCount; //调用get()时是第几次查询
public:
    priority_queue<pair<int, string> , vector<pair<int, string>>, cmp_min> minHeap;
    priority_queue<pair<int, string> , vector<pair<int, string>>, cmp_max> maxHeap;

    SORTracker() {
        queryCount = 1;
    }

    void add(string name, int score) {
        maxHeap.emplace(score, name);

        if( minHeap.size() < queryCount && maxHeap.top() < minHeap.top()){
            cout << maxHeap.size() << endl;
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
            cout << "添加{" << name + ", " + to_string(score) << "}到小根堆中" << endl;
        }else{
            cout << "添加{" << name + ", " + to_string(score) << "}到大根堆中" << endl;
        }
    }

    string get() {
        string res = minHeap.top().second;
        minHeap.emplace(maxHeap.top());
        maxHeap.pop();
        queryCount ++;
        cout << "第" + to_string(queryCount - 1) + "次查询，查询结果景点为 " << res << endl;
        return res;
    }
};

int main(){
//    SORTracker* sor = new SORTracker();
//    sor->add("xian", 5);
//    sor->get();
    SORTracker* tracker = new SORTracker(); // 初始化系统
    tracker->add("bradford", 2); // 添加 name="bradford" 且 score=2 的景点。
    tracker->add("branford", 3); // 添加 name="branford" 且 score=3 的景点。
    tracker->get();              // 从好带坏的景点为：branford ，bradford 。
    // 注意到 branford 比 bradford 好，因为它的 评分更高 (3 > 2) 。
    // 这是第 1 次调用 get() ，所以返回最好的景点："branford" 。
    tracker->add("alps", 2);     // 添加 name="alps" 且 score=2 的景点。
    tracker->get();              // 从好到坏的景点为：branford, alps, bradford 。
    // 注意 alps 比 bradford 好，虽然它们评分相同，都为 2 。
    // 这是因为 "alps" 字典序 比 "bradford" 小。
    // 返回第 2 好的地点 "alps" ，因为当前为第 2 次调用 get() 。
    tracker->add("orland", 2);   // 添加 name="orland" 且 score=2 的景点。
    tracker->get();              // 从好到坏的景点为：branford, alps, bradford, orland 。
    // 返回 "bradford" ，因为当前为第 3 次调用 get() 。
    tracker->add("orlando", 3);  // 添加 name="orlando" 且 score=3 的景点。
    tracker->get();              // 从好到坏的景点为：branford, orlando, alps, bradford, orland 。
    // 返回 "bradford".
    tracker->add("alpine", 2);   // 添加 name="alpine" 且 score=2 的景点。
    tracker->get();              // 从好到坏的景点为：branford, orlando, alpine, alps, bradford, orland 。
    // 返回 "bradford" 。
    tracker->get();              // 从好到坏的景点为：branford, orlando, alpine, alps, bradford, orland 。
    // 返回 "orland" 。

    return 0;
}