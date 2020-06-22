//
//  main.cpp
//  Stack
//
//  Created by Ira Xavier Porchia on 5/22/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 1000;

//class Stack{
//private:
//    int _top;
//public:
//    int _data[MAX];
//
//    Stack():
//    _top(-1){}
//
//    bool push(int value){
//        if(_top >= (MAX - 1)){
//            cout << "Stack Overflow" << endl;
//            return false;
//        }
//        _data[++_top] = value;
//        cout << value << " pushed into stack \n" << endl;
//        return true;
//    }
//
//    int pop(){
//        if(_top < 0){
//            cout << "Stack Underflow" << endl;
//            return 0;
//        }
//        int value = _data[_top--];
//        return value;
//    }
//
//    int peek(){
//        if (_top < 0) {
//            cout << "Stack is Empty";
//            return 0;
//        }
//        else {
//            int value = _data[_top];
//            return value;
//        }
//    }
//
//    bool isEmpty(){
//        return (_top < 0);
//    }
//
//};

class node{
    friend class LStack;
private:
    int _data;
    node *_next;
public:
    node(int data):
    _data(data), _next(nullptr){}
};

class LStack{
private:
    node *_head;
public:
    LStack():
    _head(nullptr){}
    
    ~LStack(){
        if(_head == nullptr){
            return;
        }
        node *p;
        while(_head != nullptr){
            p = _head;
            _head = _head->_next;
            p->_next = nullptr;
            delete p;
        }
    }
    
    void push(int data){
        if(_head == nullptr){
            _head = new node(data);
            cout << _head->_data << " was pushed in the stack.\n" << endl;
            return;
        }
        node *p = new node(data);
        p->_next = _head;
        _head = p;
        cout << p->_data << " was pushed in the stack.\n" << endl;
    }
    
    int pop(){
        if(_head == nullptr){
            cout << "Can't pop out of an empty stack.\n" << endl;
            return 0;
        }
        node *p = _head;
        _head = _head->_next;
        p->_next = nullptr;
        return p->_data;
    }
    
    void peek(){
        cout << _head->_data << "\n" << endl;
    }
    
};

int main(int argc, const char * argv[]) {
//    Stack s;
//    s.push(10);
//    s.push(20);
//    s.push(30);
//    cout << s.pop() << " Popped from stack\n";
//    cout << s.pop() << " Popped from stack\n";
//    cout << s.pop() << " Popped from stack\n";
//    cout << s.pop() << " Popped from stack\n";
    
    LStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.peek();
    cout << s.pop() << " Popped from stack\n" << endl;
    cout << s.pop() << " Popped from stack\n" << endl;
    cout << s.pop() << " Popped from stack\n" << endl;
    cout << s.pop() << " Popped from stack\n" << endl;
    return 0;
}
