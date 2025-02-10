#ifndef SEARCH_H
#define SEARCH_H

namespace searching{
template <typename T>
int binary_search(T *s,T *e, T key)
{
    T* l = s;
    T* r = e-1;
    while (l <= r)
    {
        T* m = l + (r - l) / 2;
        if (*m == key)
        {
            return m-s;
        }
        else if (*m > key)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

template <typename T>
int linear_search(T *s, T *e, T key)
{
    for (const T* it = s; it != e; it++)
    {
        if (*it == key)
        {
            return it-s;
        }
    }
    return -1;
}

}
#endif 