#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

template < class x > void swaper(x &a , x &b) {
    x t = a;
    a = b;
    b = t;
}

void rearrange_array(int arr[] , int n) {
    int p = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            p++;
            swaper(arr[i] , arr[p]);
        }
    }

   // cout << p << endl;
    int neg = 0;
    int pos = p+1;

    while(neg < pos && pos < n && arr[neg] < 0) {
        swaper(arr[neg] , arr[pos]);
        neg += 2;
        pos += 1;
    }
}
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = ARRAY_SIZE(arr);

    rearrange_array(arr , n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
return 0;
}
