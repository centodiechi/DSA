#include <iostream>
#include <functional>
using namespace std;

template <typename T, typename Comparator = std::less<T>>
void insertion_sort(T *s, T *e,Comparator comp = Comparator())
{      
        int n = e - s;
        for (int i = 1; i < n; i++)
        {
            T key =s[i];
            int j=i-1;
            while(j>=0 && comp(key,s[j])){
                s[j+1]=s[j];
                j--;
            }
            s[j+1]=key;
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
    insertion_sort(Tarr,Tarr+n);
    cout<<"Insertion Sort"<<endl;
    Print(Tarr,n);
    return 0;
}