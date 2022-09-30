//
// Created by admin on 2022/9/21.
//

#include <bits/stdc++.h>
#include <thread>
#include <memory>
#include "DesignPattern_Singleton.h"
// memory: unique_ptr


using namespace std;

void Print(int x){
    thread::id this_id = this_thread::get_id();
    cout << "Print's id:" << this_id << endl;
    cout << "Print's id hashCode : " << hash<thread::id> ()(this_id) << endl;
    while(x-- > 0) cout << x << endl;
}

class Base{
public:
    void run(int x){
        while(x-- > 0)
            cout << x << endl;
    }

    static void run1(int& x){

        while(x-- > 0) cout << x << endl;
    }

};

/* 智能指针 */
void Print2(unique_ptr<int> ptr)
{
    cout << "子线程.." << *ptr.get() << endl;
    cout << this_thread::get_id() << endl;
}

///测试future基本用法
void futureTest(){
    //通过async来获取异步操作结果
    std::future<int>  result = std::async([](){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        return 8;
    });

    std::cout << "the future result : " << result.get() << std::endl;
    std::cout << "the future status : " << result.valid() << std::endl;
    try
    {
        result.wait();  //或者 result.get() ,会异常
        //因此std::future只能用于单线程中调用 ，多线程调用使用std::share_future();
    }
    catch (...)
    {
        std::cout << "get error....\n ";
    }
}

/// 测试std::promise和std::future同时使用的用法
void get_int(std::promise<int>& prom) {             // 1.参数为 promise
    int x;
    std::cout << "Please, enter an integer value: ";
    std::cin.exceptions(std::ios::failbit);         // 设置failbit
    try {
        std::cin >> x;
        prom.set_value(x);
    }
    catch (std::exception&) {
        prom.set_exception(std::current_exception());
    }
}

void print_int(std::future<int>& fut) {             // 2.参数为 future
    try {
        int x = fut.get();
        std::cout << "value: " << x << '\n';
    }catch (std::exception& e) {
        std::cout << "[exception caught: " << e.what() << "]\n";
    }
}

///测试promise两次set_value，结果：会报错
void test(std::promise<int>& para){
    para.set_value(10);
    para.set_value(20);
    return;
}
/*
void promiseTest(){
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread th1(print_int, std::ref(fut));      // 3. 该线程获取 共享状态值
    std::thread th2(get_int, std::ref(prom));       // 4. 该线程设置 共享状态值

    th1.join();
    th2.join();

    std::promise<int> pro;
    std::future<int> T = pro.get_future();
    std::thread fun(test, std::ref(pro));
    fun.join();
    cout << T.get() << endl;
}*/

/// 测试promise传入可变元函数
using F = std::function<int(int, int, int&)>;		//等同于typedef std::function<int(int, int, int&)> F;

//函数可以改成任意参数，任意返回类型
int Test_Fun(int a, int b, int &c)
{
    //a = 1, b = 2
    c = a + b + 230;
    return c;
}

void Thread_Fun1(std::promise<F> &p)
{
    //为了突出效果，可以使线程休眠5s
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "传入函数Test_Fun" << std::endl;

    //传入函数Test_Fun
    p.set_value(std::bind(&Test_Fun, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

template<typename T, typename ...Args>
void Thread_Fun2(std::future<T> &f, Args&& ...args)
{
    //阻塞函数，直到收到相关联的std::promise对象传入的数据
    auto fun = f.get();		//fun等同于Test_Fun

    auto fResult = fun(std::forward<Args>(args)...);

    std::cout << "收到函数并运行，结果：" << fResult << std::endl;
}

// 将函数作为参数通过promise传入共享状态
void promise_fun(){
    //声明一个std::promise对象pr1，其保存的值类型为int
    std::promise<F> pr1;
    //声明一个std::future对象fu1，并通过std::promise的get_future()函数与pr1绑定
    std::future<F> fu1 = pr1.get_future();

    //声明一个变量
    int iVal = 0;

    //创建一个线程t1，将函数Thread_Fun1及对象pr1放在线程里面执行
    std::thread t1(Thread_Fun1, std::ref(pr1));
    //创建一个线程t2，将函数Thread_Fun2及对象fu1放在线程里面执行
    std::thread t2(Thread_Fun2<F, int, int, int&>, std::ref(fu1), 1, 2, std::ref(iVal));

    //阻塞至线程结束
    t1.join();
    t2.join();
}

class A{
public:
    void show(int a, int b, int c){
        cout << "A::show()，被重载函数" << endl;
    }
    virtual void show1(int a, int b){}
    virtual void show2(int u, int v)final{
        cout << "A::show1()" << u << endl;
    } //final修饰的虚函数无法被重写（覆盖）
    virtual void show3() = 0;   // 纯虚函数，有纯虚函数的类不能生成对象，相当于抽象类

    void show4(int a){
        cout << "A::show4()" << endl;
    };
    void show5(int a){
        cout << "A::show5()" << endl;
    };
    virtual void show6(int a){
        cout << "A::show6()" << endl;
    };
};

class B: public A{
public:
    // 重载
    void show(int a, int b){
        cout << "B::show()，重载成功 a = " << a << endl;
    }
    // 重写（覆盖）
    void show1(int a, int b) override{
        cout << "B::show1(),重写成功" << endl;
    }
    void show3(){       // 只有实现基类的纯虚函数以后，才能生成该派生类的对象
        cout << "B::show3()" << endl;
    }
    void show4(){       // 隐藏 ==> 普通函数|不同参
        cout << "B::show4()，隐藏成功==>普通函数|同参" << endl;
    }
    void show5(int a){  // 隐藏==>普通函数|同参
        cout << "B::show5()，隐藏成功==>普通函数|同参" << endl;
    }
    virtual void show6(){       // 隐藏 ==> 虚函数|不同参
        cout << "B::show6()，隐藏成功 ==> 虚函数|不同参" << endl;
    };


};

int main(){



    /* 继承、多态的测试 */
    B b;
    b.show4();                  // 隐藏普通函数（不同参
    b.show5(5);              // 隐藏普通函数(同参
    b.show6();                  // 隐藏虚函数（不同参
    cout << "---------基类指针指向派生类对象测试---------" << endl;
//    b.show(1,2,3);
    /* 基类指针指向派生类对象 */
    A* a = new B();
    a->show(1,2,3);    // 调用普通重载函数时（无virtual），调用基类的函数
    a->show1(5,4);        // 调用虚函数时，如果派生类对虚函数进行重写，则调用派生类的虚函数
    a->show4(4);
    a->show5(6);             //
    a->show6(2);


//    futureTest();
//    promiseTest();
/*
    // 空线程，非joinable
    thread t;

    // 普通函数
    thread t1(Print, 9);
//    t1.detach();
    t1.join();

    // 静态成员函数, 传递引用必须使用ref()
    int n = 12;
    thread t2(Base::run1, std::ref(n));
    t2.join();

    // 非静态成员函数
//    Base b;
//    thread t3(&Base::run, b, 11);

    // 仿函数
    thread t4([](int x){while(x-- > 0) cout << x << endl;}, 12);
    t4.join();

    // 智能指针
    unique_ptr<int> ptr(new int(1000));
    thread t5(Print2, move(ptr));
    t5.join();

    //运行结束的线程：不会返回线程id，此时get_id()返回："thread::id of a non-executing thread"
    cout << "t1's id : " << t1.get_id() << endl;
    // this_thread::get_id() 获取当前所在线程的id
    cout << "main's id: " << this_thread::get_id() << endl;
*/
//    Singletontest();
    return 0;
}


