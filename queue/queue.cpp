#include<iostream>
using namespace std;
template <class T>
class queue{
private:
    int front;
    int rear;
    int cap;
    T* q;
public:
    queue() {
        front=-1;
        rear=-1;
        cap=0;
    }

    ~queue() {
        delete[] q;
    }

    void push(T val) {
        if(front==-1) front=0;
        if(cap==0){
            cap=1;
            q=new T[cap];
        }
        if(rear==cap-1) {
            T cpy[cap];
            cap*=2;
            for(int i=0;i<=rear;i++) {
                cpy[i]=q[i];
            }
            delete[] q;
            q = new T[cap];
            for(int i=0;i<=rear;i++){
                q[i]=cpy[i];
            }
        }
        q[++rear]=val;
    }

    void pop() {
        if(front==rear) front=rear=-1;
        else{
            front++;
        }
    }

    bool empty(){
        return rear==-1;
    }

    T Front() {
        if(front==-1) return T();
        return q[front];
    }

    T Rear() {
        if(rear!=-1) return T();
        return q[rear];
    }
};


int main() {
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.push(9);
    q.pop();
    q.pop();
    q.pop();
    q.push(19);
    while (!q.empty()){   
        cout<<q.Front()<<" ";
        q.pop();    
    }
    
    return 0;
}