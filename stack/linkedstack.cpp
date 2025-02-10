#include<iostream>
using namespace std;

template<class T>
class Node{
public:
    T data;
    Node* next;

    Node(T val){
        data=val;
        next=nullptr;
    }
};

template<class T>
class stack{
private:
    Node<T>* top;
    int size; 
public:
    stack(){
        top=nullptr;
        size=0;
    }

    void push(T val){
        Node<T>* node = new Node<T>(val);
        node->next = top;
        top = node;
        size++;
    }

    void pop(){
        if(top){
            Node<T> *t = top;
            top=top->next;
            delete t;
            size--;
        }
    }

    int Size() {
        return size;
    }

    bool empty(){
        return top==nullptr;
    }

    T Top() {
        return top->data;
    }
};


int main() {
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(7);
    s.push(0);
    s.push(9);
    s.push(6);
    while(!s.empty()){
        cout<<s.Top()<<endl;
        s.pop();
    }
    return 0;
}