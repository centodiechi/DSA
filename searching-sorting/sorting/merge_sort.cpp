#include <iostream>
#include <functional>
using namespace std;

template <typename T, typename Comparator = std::less<T>>
void merge(T *l,T *m,T *h,Comparator comp = Comparator()) {
    int leftSize = m - l;  
    int rightSize = h - m; 
    vector<T> left(l, m);
    vector<T> right(m, h);

    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (comp(left[i], right[j])) {
            l[k++] = left[i++];
        } else {
            l[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        l[k++] = left[i++];
    }

    while (j < rightSize) {
        l[k++] = right[j++];
    }
}


template <typename T, typename Comparator = std::less<T>>
void merge_sort(T *s,T *e,Comparator comp = Comparator()) {      
    if(s+1>=e){
        return;
    }
    T* m = s+(e-s)/2;
    merge_sort(s,m,comp);
    merge_sort(m,e,comp);
    merge(s,m,e);
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
    // int Tarr[] = {34, -2, 0, 5, 23, -15, 34, 89, 2, -7, 18, 34, 7, -20, 42};
    int Tarr[] = {34, -2, 1, 5, 23, -15};
    int n = sizeof(Tarr) / sizeof(Tarr[0]);

    cout << "Original Array" << endl;
    Print(Tarr, n);
    merge_sort(Tarr,Tarr+n);
    cout<<"Merge Sort"<<endl;
    Print(Tarr,n);
    return 0;
}