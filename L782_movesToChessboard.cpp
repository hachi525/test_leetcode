//
// Created by admin on 2022/8/23.
//

#include "L782_movesToChessboard.h"


int L782_movesToChessboard::getMoves(int mask, int count, int n) {
    int ones = __builtin_popcount(mask);
    if (n & 1) {
        /* 如果 n 为奇数，则每一行中 1 与 0 的数目相差为 1，且满足相邻行交替 */
        if (abs(n - 2 * ones) != 1 || abs(n - 2 * count) != 1 ) {
            return -1;
        }
        if (ones == (n >> 1)) {
            /* 偶数位变为 1 的最小交换次数 */
            return n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
        } else {
            /* 奇数位变为 1 的最小交换次数 */
            return (n + 1) / 2 - __builtin_popcount(mask & 0x55555555);
        }
    } else {
        /* 如果 n 为偶数，则每一行中 1 与 0 的数目相等，且满足相邻行交替 */
        if (ones != (n >> 1) || count != (n >> 1)) {
            return -1;
        }
        /* 偶数位变为 1 的最小交换次数 */
        int count0 = n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
        /* 奇数位变为 1 的最小交换次数 */
        int count1 = n / 2 - __builtin_popcount(mask & 0x55555555);
        return min(count0, count1);
    }
}

int L782_movesToChessboard::movesToChessboard(vector<vector<int>> &board) {
    int n = board.size();
    int rowMask = 0, colMask = 0;

    for (int i = 0; i < n; ++i) {
        rowMask |= (board[0][i] << i);
        colMask |= (board[i][0] << i);
    }



}


int main() {

    return 0;
}
