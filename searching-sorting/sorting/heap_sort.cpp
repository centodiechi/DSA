#include<iostream>
using namespace std;

template<typename T,typename Comparator = std::less<T>>
void heapify(T *arr,int n,int i,Comparator cmp = Comparator()){
    int idx=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&cmp(arr[idx],arr[left])) idx=left;
    if(right<n&&cmp(arr[idx],arr[right])) idx=right;
    if(idx!=i){
        swap(arr[idx],arr[i]);
        heapify(arr,n,idx,cmp);
    }
}


template<typename T,typename Comparator = std::less<T>>
void heap_sort(T *arr,int n,Comparator cmp = Comparator()) {
    for(int i=(n-2)/2;i>=0;i--){
        heapify(arr,n,i,cmp);
    }
    for(int i=n-1;i>0;i--) {
        swap(arr[i],arr[0]);
        heapify(arr,i,0,cmp);
    }
}

template <typename T>
void Print(T *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int Tarr[] = {34, -2, 0, 5, 23, -15, 34, 89, 2, -7, 18, 34, 7, -20, 42};
    int n = sizeof(Tarr) / sizeof(Tarr[0]);

    cout << "Original Array" << endl;
    Print(Tarr, n);
    heap_sort(Tarr,n);
    cout<<"Heap Sort"<<endl;
    Print(Tarr,n);
    return 0;
}