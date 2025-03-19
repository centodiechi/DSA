#include<iostream>
#include<vector>
#include<functional>
using namespace std;

template<class T,typename Comparator = less<T>>
class Heap  {
private:
    vector<T> heap;
    Comparator cmp;

    void heapify(int i) {
        int left = 2*i+1;
        int right = 2*i+2; 
        int idx=i;
        if(left<heap.size()&&cmp(heap[left],heap[idx])) idx=left;
        if(right<heap.size()&&cmp(heap[right],heap[idx])) idx=right;
        if(idx!=i) {
            swap(heap[idx],heap[i]);
            heapify(idx);
        }
    }

public:

    Heap(int heap_size=5){
        heap.reserve(heap_size);
    }

    Heap(const typename vector<T>::iterator s,const typename vector<T>::iterator e){
        heap = vector<T>(s,e);
        for(int i=(heap.size()-2)/2;i>=0;i--){
            heapify(i);
        }
    }

    void push(T val) {
        heap.push_back(val);
        int idx=heap.size()-1;
        int parent = (idx-1)/2;                    
        while(idx>0 && cmp(heap[idx],heap[parent])){
            swap(heap[idx],heap[parent]);
            idx=parent;
            parent=(idx-1)/2;
        }
    }
    
    T pop() {
        if(heap.size()==0) return T();
        swap(heap[0],heap[heap.size()-1]);
        T pop_val=heap.back();
        heap.pop_back();
        heapify(0);
        return pop_val;
    }

    bool empty() {
        return heap.size()==0;
    }

    T peek() {
        if(heap.size()==0) T();
        return heap[0];
    }
};




int main() {
  Heap<char> h;
  h.push('s');
  h.push('r');
  h.push('a');
  h.push('g');
  vector<int> v = {2,45,22,12,8,9,33,35,36};
  Heap<int,greater<int>> h1(v.begin(),v.end());
  while(!h1.empty()){
    cout<<h1.pop()<<" ";
  }
  cout<<endl;
  while(!h.empty()){
    cout<<h.pop()<<" ";
  }
  return 0;   
}