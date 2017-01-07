#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int minimum_jumps(int arr[] ,  int n) {
    int *jumps = new int[n];

    jumps[0] = 0;
    for(int i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for(int j = 0; j < i; j++) {
            if(jumps[j] != INT_MAX && i <= j + arr[j])
                jumps[i] = min(jumps[i] , jumps[j]+1);
        }
    }
    return jumps[n-1];
}
int main()
{
    int arr[] = {1, 3, 6, 1, 0, 9};
    int n = ARRAY_SIZE(arr);

    int jumps = minimum_jumps(arr , n);
    cout << "Minimum jumps required is " << jumps << endl;

return 0;
}
