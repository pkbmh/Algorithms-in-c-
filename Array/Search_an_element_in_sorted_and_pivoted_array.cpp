#include <bits/stdc++.h>
using namespace std;

int find_pivot_index(int arr[] , int l , int h) {
    if(l > h)
        return -1;
    if(l == h)
        return l;
//1 1 1 0 1 1 1 1 1 1
    int mid = (l+h) / 2;

    if(mid < h && arr[mid] > arr[mid+1])
        return (mid);
   if(mid > l && arr[mid] < arr[mid-1])
        return (mid-1);

    if(arr[l] >= arr[mid])
        return find_pivot_index(arr , l , mid);
    else
        return find_pivot_index(arr , mid+1 , h);

}
int binary_search(int arr[] , int l , int h , int key) {
    if(l > h)
        return -1;

    int mid = (l+h)/2;

    if(arr[mid] == key)
        return mid;
    if(arr[mid] < key)
        return binary_search(arr , (mid+1) , h , key);
    else
        return binary_search(arr , l , (mid-1) , key);
}
int search_key(int arr[] ,  int size , int key) {
    int pivot_index = find_pivot_index(arr , 0  , size-1);

  //  cout << "Pivot index is " << pivot_index << endl;

    if(pivot_index == -1)
        return binary_search(arr , 0 , size-1 , key);
    if(arr[pivot_index] == key)
        return pivot_index;
    if(arr[0] <= key)
        return binary_search(arr , 0 , pivot_index-1 , key);
    else
        return binary_search(arr , pivot_index+1 , size-1 , key);
}

int main()
{
    int n;
    cout << "Enter number of element in array " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter array" << endl;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter key to search " << endl;
    cin >> key;

    int pivot_index = search_key(arr , n-1 , key);
    //int pivot_index = find_pivot_index(arr , 0 , n-1);
    cout << "index of searched key is  = " << pivot_index << endl;


return 0;
}
