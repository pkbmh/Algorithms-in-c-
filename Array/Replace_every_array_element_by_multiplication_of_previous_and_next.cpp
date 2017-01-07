#include <bits/stdc++.h>
using namespace std;

void replace_element(int arr[] , int n) {
    int pre = arr[0];
    int cur;
    arr[0] = arr[0] * arr[1];
    //arr[n-1] = arr[n-1] * arr[n-2];

    for(int i = 1; i < n-1; i++){
        cur = arr[i];
        arr[i] = pre * arr[i+1];
        pre = cur;
    }
    arr[n-1] = arr[n-1] * cur;
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

    replace_element(arr , n );

    cout << "modified array is " << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " " ;


return 0;
}
