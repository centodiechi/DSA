#include<iostream>
using namespace std;
template<class T>
class stack{
private:
    T *stk;
    int cap;
    int top;
public:
    stack(){
        top=-1;
        cap=0;
    }

    ~stack() {
        delete[] stk;
    }

    void push(T val) {
        if(cap==0) {
            cap=1;
            stk = new T[cap];
        }
        if(top+1==cap){
            cap*=2;
            T arr[top+1];
            for(int i=0;i<=top;i++){
                arr[i]=stk[i];
            }
            delete[] stk;
            stk = new T[cap];
            for(int i=0;i<=top;i++){
                stk[i]=arr[i];
            }
        }
        stk[++top]=val;
    }

    void pop(){
        if(top!=-1) top--;
    }

    bool empty(){
        return top==-1;
    }

    T Top() {
        if(top==-1) return T();
        return stk[top];
    }
};

int main(){
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