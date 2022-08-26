//
// Created by admin on 2022/7/22.
//

#include "L179_largestNumber.h"
/* 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * */
string L179_largestNumber::largestNumber(vector<int> &nums) {
    vector<string> vt;
    for(int num:nums)
        vt.push_back(to_string(num));
    sort(vt.begin(), vt.end(), [](string x, string y){
        string s1 = x, s2 = y;
        return (s1+s2)>(y+x);
    });
    string res;
    for (auto str:vt) {
        res += str;
    }
    return res[0] == '0'?"0":res;
}

void Test(){
    vector<int> nums;
    L179_largestNumber solution;
    solution.largestNumber(nums);
}

int main() {
    Test();
    return 0;
}
