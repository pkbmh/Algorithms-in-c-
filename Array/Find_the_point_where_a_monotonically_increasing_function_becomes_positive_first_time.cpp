#include <bits/stdc++.h>
using namespace std;

inline int fun(int x) {
    return (x*x - 2 * x - 20);
}

int binary_search_point(int l , int h) {
    if(l > h)
        return l;

    int mid = (l+h)/2;

    int val = fun(mid);

    if(val == 0)
        return mid;
    if(val < 0)
        return binary_search_point(mid+1 , h);
    else
        return binary_search_point(l , mid-1);
}

int find_point() {
    int i = 1;

    for(; ; i *= 2)
        if(fun(i) > 0)
            break;

    return binary_search_point(i/2 , i);
}
int main()
{
   int point = find_point();
   cout << "Function (x*x-2*x-20) first time become +ive at " << point << endl;
return 0;
}
