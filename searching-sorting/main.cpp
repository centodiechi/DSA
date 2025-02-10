#include <iostream>
#include<algorithm>
#include "searching/search.h"
using namespace std;

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
    
    int key = 23;
    int lfound = searching::linear_search<int>(Tarr, Tarr+n, key);
    cout << "Linear Search " << key << " : " << lfound << endl;
    
    sort(Tarr,Tarr+n);
    Print(Tarr,n);
    int bfound = searching::binary_search<int>(Tarr, Tarr+n, key);
    cout << "Binary Search " << key << " : " << bfound << endl;
    return 0;
}
