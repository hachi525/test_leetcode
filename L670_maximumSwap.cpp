//
// Created by admin on 2022/9/13.
//

#include <bits/stdc++.h>

using namespace std;
class Solution{

public:
    int maximumSwap(int num){
        /* 方法一： 暴力，遍历所有交换情况找到最大值 */
        string numArray = to_string(num);
        int maxNum = num;
        int n = numArray.size();
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                swap(numArray[i], numArray[j]);
                maxNum = max(maxNum, stoi(numArray));
                swap(numArray[i], numArray[j]);
            }
        }
        return maxNum;

        /* 方法二：降序排序+原数组逆序比较 */
//        char lidx = '\0';
//        int ridx = -1;
//        string array = to_string(num);
//        string str = array;
//        sort(str.begin(), str.end(), greater<char>());
//        for(int i = 0; i < str.size(); i ++){
//            if(str[i] != array[i]){
//                ridx = i;
//                lidx = array[i];
//                array[i] = str[i];
//                break;
//            }
//        }
//
//        if(lidx!= '\0')
//            for(int i = str.size()-1; i >= 0 ; i --){
//                if (array[i] == array[ridx]){
//                    array[i] = lidx;
//                    break;
//                }
//            }
//        int maxNum = stoi(array);
//        return maxNum;

        /* 方法三：贪心算法 */
//        string charArray = to_string(num);
//        int n = charArray.size();
//        int maxIdx= n-1;
//        int idx1 = -1, idx2 = -1;
//        for (int i = n-1; i >= 0; i--) {
//            if (charArray[i] > charArray[maxIdx])
//                maxIdx = i;
//            else if (charArray[i] < charArray[maxIdx]) {
//                idx1 = i;
//                idx2 = maxIdx;
//            }
//        }
//
//        if(idx1 >= 0){
//            swap(charArray[idx1], charArray[idx2]);
//            return stoi(charArray);
//        } else
//            return num;
    }
};
