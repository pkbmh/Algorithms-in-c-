#include <bits/stdc++.h>
using namespace std;

template < class x > void swaper(x &a , x &b) {
    x t = a;
    a = b;
    b = t;
}

void sort_waveform(int arr[] , int n) {
    if(arr[0] < arr[1])
        swaper(arr[0] , arr[1]);

   for(int i = 1; i < n-1; i++) {
        if(i%2) {
            if(arr[i] > arr[i-1])
                swaper(arr[i] , arr[i-1]);
            if(arr[i] > arr[i+1])
                swaper(arr[i] , arr[i+1]);
        }
   }

   if(n > 1 && !(n % 2)&& arr[n-2] < arr[n-1])
        swaper(arr[n-1] , arr[n-2]);

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

    sort_waveform(arr , n);
    cout << "Sorted wave form is " << endl;

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

return 0;
}
