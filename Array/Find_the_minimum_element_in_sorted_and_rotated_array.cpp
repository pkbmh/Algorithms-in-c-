#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

int find_minimum(int arr[] , int l , int h) {
    if(l > h)
        return l;
    if(l == h)
        return l;

    int mid = (l+h)/2;

    if(mid > l && arr[mid] <= arr[mid+1] && arr[mid] < arr[mid-1])
        return mid;
    else if(arr[mid] <= arr[h])
        return find_minimum(arr , l , mid-1);
    else
        return find_minimum(arr , mid+1 ,h);
}
int main()
{
    int arr[] = {4, 1, 2, 2, 3};
    int n = ARRAY_SIZE(arr);

    int min = find_minimum(arr , 0 , n-1);
    cout << "Minimum element is at index " << min << endl;

return 0;
}
