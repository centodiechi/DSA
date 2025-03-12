#include<iostream>
using namespace std;

template<class T>
class Node {
public:
    T val;
    Node* next;
    Node() {
        val=T();
        next=nullptr;
    }
    Node(T value) {
        val=value;
        next=nullptr;
    }
};

template<class T>
class List {
private:
Node<T>* head;
Node<T>* tail;
int size;
public:
    class iterator {
        private:
            Node<T>* itr;
        public:
            iterator() {
                itr = nullptr;
            }     

            iterator(Node<T>* nde){
                itr = nde;
            }

            T& operator*() {
                return itr->val;
            }
    
            iterator& operator++() {
                if (itr) {
                    itr = itr->next;
                }
                return *this;
            }
    
            iterator operator++(int) {
                iterator temp = *this;
                if (itr) {
                    itr = itr->next;
                }
                return temp;
            }
            bool operator==(const iterator& other) const {
                return itr == other.itr;
            }
    
            bool operator!=(const iterator& other) const {
                return itr != other.itr;
            }
    };

    List() {
        size=0;
        head=tail=nullptr;
    }
    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    ~List() {  
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
    void push_back(T val) {
        Node<T>* node = new Node(val);
        size++;
        if(!head){
            head=tail=node;
            return;
        }
        tail->next = node;
        tail=node;
    }

    void push_front(T val) {
        Node<T>* node = new Node(val); 
        size++;
        if(!head){
            head=tail=node;
            return;
        }
        node->next=head;
        head=node;
    }

    void push_n(T val,int n) {
        if(n==1) {
            push_front(val);
            return;
        }
        if(n>1&&n<=size){
            Node<T>* node = new Node(val); 
            size++;
            int cnt=1;
            Node<T>* temp=head;
            while(cnt<n-1){
                cnt++;
                temp=temp->next;
            }
            node->next=temp->next;
            temp->next=node;
        }
    }
    
    void pop_back() {
        if(!head) return;
        size--;
        if(head==tail) {
            delete head;
            head=tail=nullptr;
            return;
        }
        Node<T>* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
        tail=temp;
    }

    void pop_front() {
        if(!head) return;
        size--;
        if(head==tail) {
            delete head;
            head=tail=nullptr;
            return;
        }
        Node<T>* nxt=head->next;
        delete head;
        head=nxt;
    }

    void pop_n(int n) {
        if(n>size) return;
        size--;
        if(n==1) pop_front();
        if(n==size) pop_back();
        Node<T>* temp=head;
        while(n>2){
            temp=temp->next;
            n--;
        }
        Node<T>* curr=temp->next;
        temp->next=curr->next;
        delete curr;
    }
};


int main() {
    List<int> l;
    l.push_back(3);
    l.push_back(6);
    l.push_front(7);
    l.push_n(1,3);
    l.pop_n(2);
    l.pop_back();
    l.pop_front();
    for(List<int>::iterator it = l.begin();it!=l.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}