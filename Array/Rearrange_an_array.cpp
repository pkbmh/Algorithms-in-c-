/* Given an array of size n where all elements are in range from 0 to n-1,
 change contents of arr[] so that arr[i] = j is changed to arr[j] = i. */
#include <bits/stdc++.h>
using namespace std;

void rearrange_(int arr[] , int i , int n) {
    int val = -(i+1);
    i = arr[i]-1;

    while(arr[i] > 0) {
        int new_i = arr[i]-1;
        arr[i] = val;
        val = -(i+1);
        i = new_i;
    }
}
void rearrange_array(int arr[] , int n) {

    for(int i = 0 ; i < n; i++)
        arr[i] += 1;

    for(int i = 0; i < n; i++) {

        if(arr[i] > 0)
            rearrange_(arr , i , n);
    }

    for(int  i = 0; i < n; i++)
        arr[i] = (-arr[i])-1;

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

    rearrange_array(arr , n);

    cout << "After rearranging array become " << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " " ;
    cout << endl;

return 0;
}
