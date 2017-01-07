#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

void print_peak_element(int arr[] , int l , int h) {
    if(l > h)
        return;

    int mid = (l+h)/2;

    if(mid > l && mid < h && arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1])
        cout << arr[mid] << " ";

    print_peak_element(arr , l , mid-1);
    print_peak_element(arr , mid+1 , h);
}
int main()
{
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int n = ARRAY_SIZE(arr);

    print_peak_element(arr ,0 , n-1);
return 0;
}
