//
// Created by admin on 2022/9/22.
//
#include <bits/stdc++.h>
using namespace std;


void T1(int x1, int x2, int v1, int v2){
    if(v1 < v2) {
        cout << "NO";
        return ;
    }
//    while(x1 <= x2){
//        x1 += v1;
//        x2 += v2;
//        if(x1 == x2) {
//            cout << "YES";
//            return ;
//        }
//        if(x1 > x2)
//            break;
//    }
    for(int i = 0; i < 10000; i ++){
        if(x1+i*v1 == x2+i*v2){
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

/* 找到小于n的最大2的幂 */
void findN(long long& n){
    long long temp = n;
    temp |= temp >> 1;
    temp |= temp >> 2;
    temp |= temp >> 4;
    temp |= temp >> 8;
    temp |= temp >> 16;// 整型一般是 32 位，上面我是假设 8 位。
    temp |= temp >> 32;
    n -= (temp + 1) >> 1;
};

void T2(){
    const string waston = "waston", holmes = "holmes";
    long long T;
    cin >> T;
    string line;
    getline(cin, line);
    // 输入T组数据
    vector<long long> vecN;
    int cnt = 0;
    while(getline(cin, line)){

        stringstream ss(line);
        string word;
        ss >> word;
        vecN.emplace_back(stoi(word));
        cnt ++;
        if(cnt == T)
            break;
    }
    // 处理T组数据
    for(int i = 0; i < T; i ++){
        long long N = vecN[i];
        int count = 0;
        while(N > 1){
            if(!(N & (N-1))){   //是2的幂次方
                N /= 2;
            }else{
                findN(N);
            }
            count ++;
        }
        vecN[i] = count;
    }
    // 输出T组结果
    for (int i = 0; i < T; ++i) {
        if(vecN[i] % 2 == 1)
            cout << "Waston" << endl;
        else
            cout << "Holmes" << endl;
    }
}


/**
 * input:
 * n m
 * ...(n行，长度m的字符串)
 * output:
 *
 * */
void T3(vector<int> skills){

}

int main(){
//    T1(1, 0, 3, 2);
//    T2();
}