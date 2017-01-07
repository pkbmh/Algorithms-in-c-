#include <bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int find_max_repeating(int arr[], int n , int k) {
    for(int i = 0; i < n; i++)
        arr[arr[i]] += k;

    int max = arr[0];
    int index = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }

    return index;
}
int main()
{
    int arr[] = {2, 3, 3, 5, 3, 4, 1, 7};
    int k = 8;
    int n = ARRAY_SIZE(arr);

    int max_repeating = find_max_repeating(arr, n , k);

    cout << "Maximum repeating element is  " << max_repeating << endl;

    return 0;
}
