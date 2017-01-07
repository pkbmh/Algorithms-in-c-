#include <bits/stdc++.h>
using namespace std;

template < class x > void swaper(x &a , x &b) {
    x tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int partition_array(int arr[] , int l , int h) {
    int p = l-1;
    int x = arr[h];

    for(int i = l; i < h; i++) {
        if(arr[i] < x) {
            p++;
            swaper(arr[i] , arr[p]);
        }
    }
    p++;
    swaper(arr[p] , arr[h]);

    return p;
}
void quick_sort(int arr[] , int l , int h) {
    if(h >= l && l >= 0) {

        int  p = partition_array(arr , l , h);
        quick_sort(arr , l , p-1);
        quick_sort(arr , p+1 , h);
    }
}

int max_contiguous_subarray(int arr[] , int n) {
    quick_sort(arr , 0 , n-1);
    int max_len = 1;
    int cur = arr[0];
    int cur_len = 1;

    for(int i = 1; i < n; i++) {
        //cout << cur << " " << arr[i] << endl;
        if(arr[i] == cur+1) {
            cur = cur+1;
            cur_len += 1;
        }
        else {
            cur = arr[i];
            max_len = max(cur_len , max_len);
            cur_len = 1;
        }
    }
    max_len = max(cur_len , max_len);
    return max_len;
}
int main()
{
    int n;
    cout << "Enter number of element in array " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter array " << endl;
    for(int  i = 0; i < n; i++)
        cin >> arr[i];

    int max_len = max_contiguous_subarray(arr , n);
    cout << "Length of maximum contiguous subarray is :: " << max_len << endl;

return 0;
}
