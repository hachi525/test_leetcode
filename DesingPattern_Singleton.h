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
        }else{

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
        }
        return instance;
    };

    class Destroy{
    public:
        ~Destroy(){
            if(Singleton1::instance){
                delete Singleton1::instance;
                cout << "~CSingleton1()" << endl;
            }
        }
    };
    static Destroy destroy1;
};
Singleton1* Singleton1::instance = nullptr;
Singleton1::Destroy destroy1;
pthread_mutex_t Singleton1::mutex = PTHREAD_MUTEX_INITIALIZER;       // 静态初始化锁变量


#endif //PROJECT_DESINGPATTERN_SINGLETON_H
