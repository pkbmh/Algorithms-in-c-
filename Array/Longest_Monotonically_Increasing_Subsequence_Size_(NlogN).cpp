#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int ceil_index(int *arr , int  l ,int h  , int x) {

        if(l > h)
            return (h+1);

        if(arr[l] >= x)
            return l;
        int mid = (l+h)/2;
        if(arr[mid] > x)
            return ceil_index(arr , l , mid-1 , x);
        else
            return ceil_index(arr , mid+1 , h , x);
}
/*
int copp(int A[], int l, int r, int key) {
    int m;

    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; // ternary expression returns an l-value
    }

    return r;
}*/

int LIS(int arr[] , int n) {
    int *tab = new int[n];
    memset(tab , 0 , sizeof(tab));
    int len;

    tab[0] = arr[0];
    len = 1;

    for(int i = 1; i < n; i++) {

        if(arr[i] < tab[0])
            tab[0] = arr[i];
        else if(arr[i] > tab[len-1])
            tab[len++] = arr[i];
        else
            tab[ceil_index(tab , 0 , len-1 , arr[i])] = arr[i];
    }
    return len;
}
int main()
{
   // int arr[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = ARRAY_SIZE(arr);

    int lis_len = LIS(arr , n);
    cout << "Length of LIS " << lis_len << endl;

return 0;
}
