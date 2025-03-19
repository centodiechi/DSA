#include<iostream>
using namespace std;

template<class T1,class T2>
class Node {
public:
    T1 key;
    T2 value;
    Node* next;
    
    Node(T1 key,T2 value) {
        this->key=key;
        this->value=value;
        next = nullptr;
    }
};

template<class T1,class T2>
class HashMap {
private:

Node<T1,T2>** hmap;
int ts;
int cs;

int hashFn(T1 key) {
    return hash<T1>{}(key);
}

void resize() {
    Node<T1,T2>** prev_hmap = hmap;
    int prevs_ts=ts;
    cs=0;
    ts*=2;
    hmap = new Node<T1,T2>*[ts]();
    for(int i=0;i<prevs_ts;i++){
        Node<T1,T2>* cur = prev_hmap[i];
        while(cur!=nullptr){
            insert(cur->key,cur->value);
            Node<T1,T2>* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
    delete[] hmap;
}

public:
    HashMap(int ds=7) {
        ts=ds;
        cs=0;
        hmap = new Node<T1,T2>*[ds]();
    }

    ~HashMap() {
        for (int i = 0; i < ts; i++) {
            Node<T1, T2>* current = hmap[i];
            while (current != nullptr) {
                Node<T1, T2>* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] hmap;
    }

    void insert(T1 key,T2 value) {
        int idx = hashFn(key);
        Node<T1,T2>* curr = hmap[idx];
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value;  
                return;
            }
            curr = curr->next;
        }

        Node<T1, T2>* newNode = new Node<T1, T2>(key, value);
        newNode->next = hmap[idx];
        hmap[idx] = newNode;
        cs++;

        if ((float)cs / ts > 0.7) {
            resize();
        }
    }

    T2* find(T1 key) {
        int idx = hashFn(key);
        Node<T1,T2>* curr = hmap[idx];
        while (curr != nullptr) {
            if (curr->key == key) return &(curr->value);
            curr = curr->next;
        }
        return nullptr;
    }


    void remove(T1 key) {
        int idx = hashFn(key);
        Node<T1,T2>* curr = hmap[idx];
        Node<T1,T2>* prev = nullptr;
        while (curr != nullptr) {
            if (curr->key == key) {
                if(!prev) {
                    hmap[idx] = curr->next;
                }else{
                    prev->next=curr->next;
                }
                delete curr;
                cs--;
                return;
            }
            prev=curr;
            curr = curr->next;
        }
    }

    T2& operator[](T1 key) {
        T2* val = find(key);
        if(!val){
            insert(key,T2());
            val = find(key);
        } 
        return *val;
    }

    int size() {
        return cs;
    }

    void print() {
        for (int i = 0; i < ts; i++) {
            Node<T1, T2>* current = hmap[i];
            cout << "Bucket " << i << ": ";
            while (current != nullptr) {
                cout << "(" << current->key << ", " << current->value << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }
};


int main() {
    HashMap<int,int> h;
    h[2];
    h[1]=-23;
    h.print();    
    return 0;
}