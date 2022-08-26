//
// Created by admin on 2022/7/23.
//
#include <iostream>
#include <vector>


using namespace std;

template <class T>
class Stack{
private:
    int _size;
    vector<T> elems;
public:
    void push(T const&);
    void pop();
    T top() const;

};

template <class T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem);
}

template<class T>
void Stack<T>::pop() {
    if (elems.empty()){
        throw out_of_range("Stack<>::pop():empty stack");
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const {
    if (elems.empty())
        throw out_of_range("Stack<>::top():empty stack");
    return elems.back();
}
