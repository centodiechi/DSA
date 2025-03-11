#include<iostream>
using namespace std;


template<class T>
class Dequeue {
private:
T *deque;
int front;
int rear;
int size;
public:

Dequeue(int k) {
    deque = new T[k];
    front=-1;
    rear=-1;
    size=k;
}

~Dequeue() {
    delete[] deque;
}

bool insertFront(T value) {
    if(isFull()) return false;
    if(front==-1) {
        front=rear=0;
        deque[front]=value;
        return true;
    }
    if(front==0) front=size;
    front--;
    deque[front]=value;
    return true;
}

bool insertLast(T value) {
    if(isFull()) return false;
    if(front==-1) {
        front=rear=0;
        deque[rear]=value;
        return true;
    }
    rear=(rear+1)%size;
    deque[rear]=value;
    return true;
}

bool deleteFront() {
    if(isEmpty()) return false;
    if(front==rear) {
        front=rear=-1;
        return true;
    }
    front=(front+1)%size;
    return true;
}

bool deleteLast() {
    if(isEmpty()) return false;
    if(front==rear) {
        front=rear=-1;
        return true;
    }
    if(rear==0) rear=size;
    rear--;
    return true;
}

int getFront() {
    if(isEmpty()) return T();
    return deque[front];
}

int getRear() {
    if(isEmpty()) return T();
    return deque[rear];
}

bool isEmpty() {
    return front==-1;
}

bool isFull() {
    return (rear+1)%size==front;    
}
};

int main() {
    Dequeue<int> dq(3);
    dq.insertFront(2);
    dq.insertFront(3);                
    dq.insertLast(5);
    while(!dq.isEmpty()){
        cout<<dq.getFront()<<" ";
        dq.deleteFront();
    }
    return 0;
}