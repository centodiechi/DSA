#include <iostream>
#include <functional>
using namespace std;



template <typename T, typename Comparator = std::less<T>>
int partition(T *l, T *h,Comparator comp = Comparator()) {
    T pivot = *(h - 1);
    int i = 0;
    for (int j = 0; j < h - l - 1; j++) {  
        if (comp(l[j], pivot)) {
            swap(l[i++], l[j]); 
        }
    }
    swap(l[i], *(h - 1)); 
    return i; 
}


template <typename T, typename Comparator = std::less<T>>
void quick_sort(T *s, T *e,Comparator comp = Comparator())
{      
    if(s+1>=e){
        return;
    }
    int p = partition(s,e,comp);
    quick_sort(s,s+p,comp);
    quick_sort(s+p+1,e,comp);
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
    quick_sort(Tarr,Tarr+n);
    cout<<"Quick Sort"<<endl;
    Print(Tarr,n);
    return 0;
}