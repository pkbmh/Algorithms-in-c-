#include <bits/stdc++.h>
using namespace std;

int find_once_occurring(int arr[] , int n) {
    int once = arr[0];

    for(int i = 1; i < n; i++)
        once = once ^ arr[i];

    return once;
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

    int once = find_once_occurring(arr , n);

    cout << "Once appearing element is :: " << once << endl;

return 0;
}
