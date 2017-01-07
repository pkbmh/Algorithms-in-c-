#include <bits/stdc++.h>
using namespace std;

int find_smallest_number(int arr[],  int n) {

    int val = 1;

    for(int i = 0; i < n && arr[i] <= val; i++)
        val += arr[i];

    return val;
}
int main()
{
    int n;
    cout << "Size of array " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter array " << endl;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int smallest = find_smallest_number(arr , n);
    cout << " Number is " << smallest << endl;

return 0;
}
