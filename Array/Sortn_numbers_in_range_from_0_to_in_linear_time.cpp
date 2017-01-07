#include <bits/stdc++.h>
using namespace std;

void count_sort(int arr[] , int exp , int n) {
    int output[n],count[n];
    int i;

    for(i = 0; i < n; i++)
        count[i] = 0;

    for(i = 0; i < n; i++)
        count[(arr[i] / exp)%n]++;

  /*  for(i = 1; i < n; i++) {
        count[i] += count[i-1];
        cout << count[i] << " ";
    }*/
    cout << endl;

    for (i = n - 1; i >= 0; i--){
        output[count[(arr[i]/exp)%n] - 1] = arr[i];
        count[(arr[i]/exp)%n]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];

}

void sort_arr(int arr[] , int n) {
    count_sort(arr , 1 , n);
    count_sort(arr , n , n);
}
int main()
{
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    int arr[n];

    cout << "Enter number range(0 to n^2)" << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort_arr(arr , n);

    cout << "After sorting array is " << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

return 0;
}
