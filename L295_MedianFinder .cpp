//
// Created by admin on 2022/8/29.
//

#include <queue>
#include <vector>
#include <set>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> minQue;     // 大根堆，存储小于等于中位数的数
    priority_queue<int, vector<int>, greater<int>> maxQue;  // 小根堆，存储比中位数大的数

    MedianFinder(){}

    void addNum(int num){
        if(minQue.empty() || num <= minQue.top()){
            maxQue.push(num);
            //如果把num加入minQue中后，数量还比maxQue多至少2个，说明num应该加入到maxQue中
            if(maxQue.size() + 1 < minQue.size()){
                maxQue.push(num);
                minQue.pop();
            }
        } else{
            maxQue.push(num);
            if(maxQue.size() > minQue.size()){// 如果maxQue中的数比minQue中的多
                maxQue.pop();
                minQue.push(num);
            }
        }
    }

    double findMedian(){
        if(maxQue.size() < minQue.size()){
            return minQue.top();
        }
        return (maxQue.top() + minQue.top())/2;
    }
};



class MedianFinder2 {
    multiset<int> nums;
    multiset<int>::iterator left, right;

public:
    MedianFinder2() : left(nums.end()), right(nums.end()) {}

    void addNum(int num) {
        const size_t n = nums.size();

        nums.insert(num);
        if (!n) {   // 集合为空
            left = right = nums.begin();
        } else if (n & 1) { // 插入前集合有偶数个数字
            if (num < *left) {
                left--;
            } else {
                right++;
            }
        } else {    // 插入前集合有奇数个数字
            if (num > *left && num < *right) {
                left++;
                right--;
            } else if (num >= *right) {
                left++;
            } else {
                right--;
                left = right;
            }
        }
    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};
