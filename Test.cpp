//
// Created by admin on 2022/7/28.
//

#include "Test.h"

class Test{
public:
    int a(int a, int b){
        return a;
    };
};

class mySequence{
private:
    int m_value;
public:
    mySequence(int ivalue):m_value(ivalue){}

    int operator()(){
        return m_value++;
    }
};


void test(){
    /* 测试unordered_map */
    unordered_map<int, int> map;
    map.emplace(1,2);
    cout << " ?"<< map.size();
    map.clear();
    cout << " ?"<< map.size();
    map.emplace(1,2);
    unordered_map<int, int >::iterator iter =  map.emplace_hint(map.begin(),3, 1);  //将键值对3-1插入map中
    pair<unordered_map<int,int>::iterator , bool> a = map.emplace(1, 2);
    map.erase(1);
    cout << " ?"<< map.size();
    cout << " bucket_count:"<< map.bucket_count() << ",load_factor:" << map.load_factor() << endl;
    map.rehash(20);
    cout << map.bucket_count() << endl;
    map.reserve(10);

    /* 测试generate()和generate_n()*/
    list<int> tempList;
    tempList.emplace(tempList.begin(), 5);
    generate_n(front_inserter(tempList),9,mySequence(1));
    generate_n(back_inserter(tempList),9,mySequence(1));
    for(list<int>::iterator it = tempList.begin(); it!= tempList.end(); it++){
        cout << *it << ", ";
    }

    /* 测试array */
    array<int, 5> arr{0, 1, 3, 4, 5};
    cout << "\n" << get<1>(arr) << ", ";

}

int fun1(int i, int j){
    cout << i  << j ;
    return 1;
}

void fun2(int (*fun1)(int i, int j), int a){
    (*fun1)(1,2);
}

class Base{
private:
    int  m_i, m_j;
public:
    Base(int i): m_j(i), m_i(m_j){}
    Base():m_j(0), m_i(m_j){}
    int get_i() const{
        return m_i;
    }
    int get_j() const{
        return m_j;
    };
};

unsigned popcnt(unsigned n){
    unsigned count = 0;
    while(n){
        count ++;
        n &= (n-1);
    }
    return count;
}

int main() {
//    test();
//
//    /* 函数指针 */
//    int (*pfun)(int i, int j);
//    pfun = fun1;
//    fun2(pfun, 2);
//    fun2(fun1, 3);
//
//    /* 成员函数指针调用成员函数 */
//    Test obj;
//    int (Test::*funptr)(int , int );    //成员函数指针
//    funptr = &Test::a;
//    (obj.*funptr)(1,2);
//
//    /* 哈希结构模板函数 */
//    cout << boolalpha << (bool)(hash<int>()(5) == hash<int >()(2));
//    sparse_popcnt();
//    _builtin_popcount_
    Base obj(98);
    cout << obj.get_i() << " , " << obj.get_j();
    return 0;
}
