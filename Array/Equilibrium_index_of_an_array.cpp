#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int equilibrium_index(int arr[] , int n) {
    int sum = 0;
    int left = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    for(int i = 0; i < n; i++) {
        sum -= arr[i];
        if(left == sum)
            return i;
        left += arr[i];
    }
    return -1;
}
int main()
{
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = ARRAY_SIZE(arr);

    int eqi = equilibrium_index(arr , n);
    cout << "Equilibrium index is " << eqi << endl;

return 0;
}
