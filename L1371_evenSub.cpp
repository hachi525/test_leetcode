//
// Created by admin on 2022/8/30.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//二进制位表示——前缀和 + 状态压缩
/* 时间复杂度：O(n)O(n)，其中 nn 为字符串 ss 的长度。只需要遍历一遍字符串即可求得答案
 * 空间复杂度：O(S)O(S)，其中 SS 表示元音字母压缩成一个状态数的最大值，在本题中 S = 32S=32。
 *      我们需要对应 SS 大小的空间来存放每个状态第一次出现的位置，因此需要 O(S)O(S) 的空间复杂度。
 */
class Solution{
public:
    int findTheLongestSubstring(string s) {
        int res = 0, status = 0, n = s.length();
        vector<int> pos(1 << 5, -1);
        pos[0] = 0;
        /* 1.使用status = 0异或运算，代表二进制数每一位都代表一个字母出现的奇偶次
         *      如00001代表截至到目前位置字母'a'出现了奇数次
         * --'a'时，status和1<<0异或运算：如果status位00001，异或后位00000，
         *      也就是说原本a有奇数次，当前又出现一次，也就是偶数次
         * 2.对于pos数组的使用，设置初始值为-1
         *      pos数组是用来存储每一种不同status对应的字符串长度
         * 1) pos[status]：存储奇偶性状态第一次出现的数组下标
         *      · 如果为-1，说明该status状态没有更新过，此时需要更新status对应字符串长度
         *    也就是从0到当前位置i，即字符串长度为 i+1
         *      · 如果不是-1，说明此前存过一次相同status的字符串长度，选择两个长度里最大的一个
         *      · status为5位二进制数，转换十进制则是32，所以pos数组大小定位2<<status.size()
         *
         * 2) i+1-pos[status]:
         *  当前位置满足status的字符串长度
         * */
        for (int i = 0; i < n; ++i) {
            switch(s[i]){
                case 'a':
                    status ^= 1<<0;
                    break;
                case 'e':
                    status ^= 1<<1;
                    break;
                case 'i':
                    status ^= 1<<2;
                    break;
                case 'o':
                    status ^= 1<<3;
                    break;
                case 'u':
                    status ^= 1<<4;
                    break;
            }
            if(~pos[status])
                res = max(res, i + 1 - pos[status]);
            else // 如果是-1，取反为0，则说明状态没发生变化，更新该位置的状态
                pos[status] = i + 1;
        }
        return res;
    }
};

int main(){

    Solution solution;
    string s;
    cin >> s ;
    cout << solution.findTheLongestSubstring(s) << endl ;


    return 0;
}
