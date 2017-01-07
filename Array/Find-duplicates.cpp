#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

void print_duplicate(int arr[] , int n) {
    for(int i = 0; i < n; i++) {
        if(arr[abs(arr[i])]  >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 1, 3, 6, 6};
    int n = ARRAY_SIZE(arr);

    print_duplicate(arr , n);

return 0;
}
