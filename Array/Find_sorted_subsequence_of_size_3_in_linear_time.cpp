#include <bits/stdc++.h>
using namespace std;

void find_sorted_subsequence(int arr[] , int n) {
   int smaller[n];
   int min = 0;

   smaller[0] = -1;

   for(int i = 1; i < n; i++) {
        if(arr[i] >= arr[min]) {
            smaller[i]  = min;
        }
        else {
            min = i;
            smaller[i] = -1;
        }
   }

   int greater[n];
   greater[n-1] = -1;
   int max = n-1;

   for(int i = n-2; i >= 0; i--) {
        if(arr[i] <= arr[max]) {
            greater[i] = max;
        }
        else {
            greater[i] = -1;
            max = i;
        }
   }

   for(int i = 0; i < n; i++) {
        if(smaller[i] != -1 && greater[i] != -1) {
            cout << arr[smaller[i]] << " " << arr[i] << " " << arr[greater[i]] << endl;
        }
   }
}
int main()
{
    int n;
    cout << "Enter number of element in array " << endl;
    cin >> n;

    int arr[n];

    cout << "Enter array " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    find_sorted_subsequence(arr, n);

return 0;
}
