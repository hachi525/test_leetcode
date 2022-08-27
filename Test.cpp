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
        return m_value*=2;
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
    //将键值对3-1插入map前面
    unordered_map<int, int >::iterator iter =  map.emplace_hint(map.begin(),3, 1);
    pair<unordered_map<int,int>::iterator , bool> a = map.emplace(1, 2);
    map.erase(1);
    cout << " ?"<< map.size();
    cout << " \nbucket_count:"<< map.bucket_count() << "\nload_factor:" << map.load_factor() << endl;
    map.rehash(20);
    cout << map.bucket_count() << endl;
    map.reserve(10);

    /* 测试generate()和generate_n()
     * generate(): 用指定函数对象产生的值去给容器指定范围内元素赋值
     * generate_n(): 一个函数对象产生的值给一定的范围内指定数目的容器元素赋值
     * */
    cout << "\n---------------------------\n测试generate_n()：" << endl;
    list<int> tempList;
    tempList.emplace(begin(tempList), 0);
    vector<int> tempV(10);
    generate(tempV.begin(), tempV.begin() + 4, [](){return 5;});
    generate(tempList.begin(), tempList.end(), mySequence(100));
    generate_n(front_inserter(tempList),4,mySequence(-1));
    generate_n(back_inserter(tempList),4,mySequence(1));
    for(list<int>::iterator it = tempList.begin(); it!= tempList.end(); it++){
        cout << *it << ", ";
    }

    /* 测试array */
    array<int, 5> arr{0, 1, 3, 4, 5};
    cout << "\n---------------------------\n测试array: \n"  << get<1>(arr) << ", ";
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

// test：虚基类构造函数中有形参
//class A{
//protected:
//    int a;
//public:
//    A(int s){ a = s; cout << "A.a = " << a << endl; }
//    void showi(){
//        cout << "A.a = " << a << endl;
//    };
//};
//
//class B: virtual public A{
//public:
//    B(int a, int b):A(a){ a += 10; cout << "B.a = " << a << " B结束 " << endl; }
//};
//
//class C : virtual public A{
//public:
//    C(int a):A(a){ a += 15; cout << "C.a = " << a << " C结束 " << endl;}
//};
//
//class D: public B, public C{
//public:
//    D(int a, int b): A(a), B(a, b), C(a){
//        cout << "B::a = " <<  a << endl;
//        cout << "C::a = " <<  a << endl;
//    }
//};



// 虚基类构造函数中没有形参
//class A{
//protected:
//    int a  =5;
//public:
//    A (){  cout << "A.a = " << a << endl; }
//    void showi(){
//        cout << "A.a = " << a << endl;
//    };
//};
//
//class B: virtual public A{
//public:
//    B( ) { a += 10; cout << "B.a = " << a << " B结束 " << endl; }
//};
//
//class C : virtual public A{
//public:
//    C( ){ a += 15; cout << "C.a = " << a << " C结束 " << endl;}
//};
//
//class D: public B, public C{
//public:
//    D( ) {
//        cout << "B::a = " <<  a << endl;
//        cout << "C::a = " <<  a << endl;
//    }
//};

//class A{
//protected:
//    int a = 5;
//public:
//    A(){ cout << "A.a = " << a << endl; };
//};
//
//class B:virtual public A{
//public:
//    B(){ cout << "B::a = " << a << endl;};
//};
//
//class C:public B{
//public:
//    C(){a+=5; cout << "C::a = " << a << endl;};
//};
//
//class D:public B{
//public:
//    D(){a+=13; cout << "D::a = " << a << endl;};
//};


class A{

public:
    int i;
    A():i(5){};
};

class B: virtual public A{
public:
    B(){i += 5;};
};

class C: virtual public A{
public:
    C(){i+=10; cout << " C.i =  " <<  i << endl;}
};

class D:public B, public C{
public:
    D(){
        cout << A::i <<endl;
        cout << B::i << endl;
        cout << C::i <<endl;
    }
};

int main() {
    /*1.任何成员对象的构造函数按照声明顺序初始化*/
//    Base obj(98);
//    cout<< obj.get_j()<< " , "  << obj.get_i() ;

//    /* 2.虚基类测试*/
//    C temp1;
//    cout << "C结束" <<endl;
    D temp ;
    cout << "D结束" << temp.i << endl;

    C c;
    cout << "c over" << c.i << endl;

//    3.测试unordered_map
//    test();

    /* 4.函数指针 */
//    int (*pfun)(int i, int j);
//    pfun = fun1;
//    fun2(pfun, 2);
//    fun2(fun1, 3);

    /* 5.成员函数指针调用成员函数 */
//    Test obj;
//    int (Test::*funptr)(int , int );    //成员函数指针
//    funptr = &Test::a;
//    (obj.*funptr)(1,2);

    /* 6.哈希结构模板函数 */
//    cout << boolalpha << (bool)(hash<int>()(5) == hash<int >()(2));
//    sparse_popcnt();
//    _builtin_popcount_

    return 0;
}
