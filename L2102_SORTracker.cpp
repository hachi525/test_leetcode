//
// Created by admin on 2022/9/1.
//
#include <queue>
#include <string>
#include <iostream>

using namespace std;

// 大顶堆
struct cmp_min{
    // a < b ====> true
    bool operator ()(const pair<int, string>& a, const pair<int, string>& b){
        if(a.first == b.first)  return a.second > b.second;
        return a.first < b.first;
    }
};

// 小顶堆
struct cmp_max{
    bool operator() (const pair<int, string>& a, const pair<int, string>& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

class SORTracker{
private:
    int queryCount; //调用get()时是第几次查询
public:
    priority_queue<pair<int, string> , vector<pair<int, string>>, cmp_max> minHeap;
    priority_queue<pair<int, string> , vector<pair<int, string>>, cmp_min> maxHeap;

    SORTracker() {
    }

/*      可以维护小根堆的大小为 get() 的次数，怎样去维护呢？
        添加值的时候先放到小根堆里面，此时小根堆的大小比get() 的次数多一；弹出小根堆的堆顶放到大根堆里，此时小根堆的大小与get() 的次数一样
*/
    void add(string name, int score) {
        // 只有当
        if(!minHeap.empty() && cmp_min()(minHeap.top(), {score, name})){
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
            minHeap.emplace(score, name);
        }else{ // minHeap.empty() || minHeap.top > {score, name}
            maxHeap.emplace(score, name);
        }
    }

    string get() {
        // 每查询一次将大根堆堆顶元素输出并放到小根堆中，那么
        // 查询后：小根堆的元素数 == 查询次数
        // 查询前：小根堆的元素数 == 查询次数 - 1
        minHeap.emplace(maxHeap.top()); // 大根堆堆顶加入小根堆
        maxHeap.pop();
        string res = minHeap.top().second;
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
    tracker->get();              // 从好到坏的景点为：branford ，bradford 。
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