#include <bits/stdc++.h>
using namespace std;
/*
if(l > h)
    return h+1;
if(l != arr[l])
    return l;
    */

int find_missing_number(int arr[] ,int l , int h) {
   // cout << " l = " << l << " h = " << h << endl;
    if(l > h)
        return h+1;
    if(l == h && arr[l] != l)
        return l;

    int mid = (l+h)/2;

    if(arr[mid] > mid && l + 1 == h)
        return mid;
    if(arr[mid] > mid)
        return find_missing_number(arr , l , mid-1);
   else
    return find_missing_number(arr , mid+1 , h);

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

    int missing = find_missing_number(arr , 0 , n-1);

    cout << "Missing element is " << missing  << endl;

return 0;
}
