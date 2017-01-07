#include <bits/stdc++.h>
using namespace std;

int search_last_occurring(int arr[] , int l , int h) {
    if(l > h)
        return -1;
    if(l == h && arr[l] == 1)
        return l;
    int mid = (l+h)/2;

    if(arr[mid] == 1 && arr[mid+1] == 0)
        return mid;
    if(arr[mid] == 0 && arr[mid-1] == 1)
        return (mid-1);

    if(arr[mid] == 0)
        return search_last_occurring(arr , l , mid-1);
    else
        return search_last_occurring(arr, mid+1 , h);
}
int main()
{
    int arr[] = {1,1,1,1,0,0,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    //int first = search_first_occurring(arr , 0 , n-1);
    int last = search_last_occurring(arr , 0 , n-1);
    cout << last+1 << endl;
return 0;
}
