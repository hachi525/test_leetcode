//
// Created by admin on 2022/9/15.
//

#ifndef PROJECT_DESINGPATTERN_SINGLETON_H
#define PROJECT_DESINGPATTERN_SINGLETON_H

/// 单例模式
// 单例模式的适用场景
//（1）系统只需要一个实例对象，或者考虑到资源消耗的太大而只允许创建一个对象。
//（2）客户调用类的单个实例只允许使用一个公共访问点，除了该访问点之外不允许通过其它方式访问该实例 (就是共有的静态方法)

//#include <bits/stdc++.h>
#include <pthread.h>
#include <iostream>

using namespace std;

/// 饿汉模式
/* 对象创建不要在头文件中，而是应该放在.cpp文件中，否则会在链接时冲突。
 * 比如在instanc.hpp中使用饿汉模式创建对象，在test.cpp和test1.cpp中进行包含这个头文件，
 * 此时单例模式就会因为有两个.cpp文件都存在，这两个文件中就会因为存在同一个同名对象而造成链接冲突
 * */
class Singleton{
private:
    Singleton(){

    }
    static Singleton * instance;
public:
    static Singleton* GetSingleton(){
        return instance;
    }
};
// 饿汉模式在main函数前就加载，全局静态变量
Singleton* Singleton:: instance = new Singleton;



/// 懒汉模式(非线程安全)
class Singleton2{
private:
    Singleton2(){

    }
    static Singleton2* instance2;
public:
    static Singleton2* GetSingleton2(){
        if(instance2 == nullptr){
            instance2 = new Singleton2();
            cout << "第一次创建实例！" << endl;
        }else{
            throw (string)"已存在一个实例，无法再次创建！";
        }
        return instance2;
    }

    //利用静态变量在程序结束会自动释放的特点
    //定义一个嵌套类专门用来释放单例对象
    class Destroy{
    public:
        ~Destroy(){
            if (Singleton2::instance2){
                delete Singleton2::instance2;
            }
        }
    };
    static Destroy destroy2;
};
//懒汉模式定义类时不创建唯一的类对象
//而是当使用的时候才唯一创建该单例的唯一对象
//所以初始化为NULL;
// 类的静态成员变量初始化应该放在类外进行初始化
Singleton2* Singleton2::instance2 = nullptr;
Singleton2::Destroy destroy2;

/// 懒汉模式（线程安全，双重锁检查）
class Singleton1{
private:
    static Singleton1* instance;
public:
    static pthread_mutex_t mutex;   //定义锁变量
    static Singleton1* Get_instance(){
        //先判断单例对象是否已经产生
        //若已经产生就不用进行加锁解锁操作直接返回对象的指针
        if(instance == NULL){
            pthread_mutex_lock(&mutex);
            cout << "Lock!" << endl;
            if(instance == nullptr)
                instance = new Singleton1();
            cout << " Init instance! " << endl;
            pthread_mutex_unlock(&mutex);
            cout << "Unlock!" << endl;
        } else
            throw (string) "instance exist!";
        return instance;
    };

    class Destroy{
    public:
        ~Destroy(){
            if(Singleton1::instance){
                delete Singleton1::instance;
                cout << "~CSingleton1 success!" << endl;
            }
        }
    };
    static Destroy destroy1;
};
Singleton1* Singleton1::instance = nullptr;
Singleton1::Destroy destroy1;
pthread_mutex_t Singleton1::mutex = PTHREAD_MUTEX_INITIALIZER;       // 静态初始化锁变量


/// 懒汉模式：使用C++11 std::call_once限制调用次数以达成线程安全 <mutex>
class Singleton3{
public:
    static Singleton3* GetInstance(){
        std::call_once(once, [&](){ instance = new Singleton3(); });
        return instance;
    }
private:
    static std::once_flag once;
    static Singleton3 *instance;
    Singleton3(){}
    Singleton3(const Singleton3&) = delete;
    void operator=(const Singleton3&) = delete;
};
Singleton3  * Singleton3::instance = nullptr;


/** 比较
 * 除了以上的方法（静态成员指针）外，还有其他的线程安全实现方法：
 * 1.静态局部对象：不再使用静态指针，而是将单例对象生成在静态区，获得地址使用&操作
 *              但是单例的释放都是在程序结束时进行
 *
 * 2.静态成员指针成员（动态释放）
 *      在Singleton1的基础上，对资源释放析构函数修改，释放资源时也使用”双重锁检查“
 *      看
 * */


void Singletontest(){
    Singleton2* ptr, *ptr1;
    try{
        ptr = ptr->GetSingleton2();
    }
    catch (string e){
        cout << e << endl;
    }
    // 尝试再创建一个实例，看是否能够创建成功
    try {
        ptr1 = ptr1->GetSingleton2();
    }catch (string e){
        cout << e << endl;
    }
};


#endif //PROJECT_DESINGPATTERN_SINGLETON_H
