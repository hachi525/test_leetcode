//
// Created by admin on 2022/9/23.
//

#ifndef PROJECT_DESIGNPATTERN_FACTORY_H
#define PROJECT_DESIGNPATTERN_FACTORY_H

#include<bits/stdc++.h>

using namespace std;

/// 简单工厂
/* 1.特点：使用工厂类封装创建具体产品对象的函数，但是扩展性差（新增种类需要修改工厂类
 *
 * 2.组成：
 *  · 工厂类：定义一个用于创建指定的具体实例对象的接口
 *  · 抽象产品类：具体产品类的继承的父类或实现的接口
 *  · 具体产品类：工厂类所创建的对象时具体产品类的实例
 * */
enum PROD_TYPE
{
    PROD_1,
    PROD_2,
    PROD_3
};
// 工厂类
class Factory{

public:

};
// 抽象产品类
class Abstract_Product{
private:

public:
    int attribution_1;
    int attribution_2;
    Abstract_Product():attribution_1(2), attribution_2(4){}
    virtual ~Abstract_Product(){
        cout << "~Abstract_Product()" << endl;
    }
    virtual void show_attribution() = 0;
};
// 具体产品类1
class PROD_1 : public Abstract_Product{
private:
    int attribution_spec1;
public:
    // 重写show_attribution()
    void show_attribution(){
        cout << attribution_1 << attribution_2 << endl;
    }
};
// 具体产品类2
class PROD_2 : public Abstract_Product{
private:
    int attribution_spec1;
public:
    // 重写show_attribution()
    void show_attribution(){
        cout << attribution_1 << attribution_2 << endl;
    }
};

/// 抽象模板工厂类
template <class AbstractProduct_t>
class AbstractFactory
{
public:
    virtual AbstractProduct_t *CreateProduct() = 0;
    virtual ~AbstractFactory() {}
};


/// 具体模板工厂类
template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t>
{
public:
    AbstractProduct_t *CreateProduct()
    {
        return new ConcreteProduct_t();
    }
};





#endif //PROJECT_DESIGNPATTERN_FACTORY_H
