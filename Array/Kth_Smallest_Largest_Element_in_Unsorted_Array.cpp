#include <bits/stdc++.h>
using namespace std;

template < class x > void swaper(x &a , x &b) {
    x tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int part(int arr[] , int l , int h) {
    int pivot = l;
    int x = arr[h];

    for(int i = l; i < h; i++) {
        if(x >= arr[i]){
           // pivot++;
            swaper(arr[i] , arr[pivot]);
            pivot++;
        }
    }
    pivot++;
    swaper(arr[h] , arr[pivot]);

    return pivot;
}
int random_partition(int arr[] , int l , int h) {
    int n = h-l+1;
    int pivot = rand()% n;
    swaper(arr[l+pivot] , arr[h]);

    return part(arr , l , h);
}
int kth_smallest_element(int arr[], int l ,int h ,int k) {
    if(l > h)
        return INT_MAX;

    int pos = random_partition(arr , l , h);
    if(pos == k)
        return arr[pos];
    if(pos < k)
        return kth_smallest_element(arr , pos+1 ,h ,k-pos);
    else
        return kth_smallest_element(arr , l , pos-1 , k);
}
int main()
{
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;

    int arr[n];

    cout << "Enter array " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k = 3;

    int kth = kth_smallest_element(arr , 0 , n-1 , k);
    cout << k << "th smallest element in array is " << kth << endl;

return 0;
}
