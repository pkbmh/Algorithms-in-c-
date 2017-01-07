#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

void find_missing_repeating(int arr[] , int n) {
    int xor1 = 0;

    for(int i = 0; i < n; i++)
        xor1 ^= arr[i] ^ (i+1);

    int set_bit = (xor1)& ~(xor1-1);

    int x = 0 , y = 0;

    for(int i = 0; i < n; i++) {
        if(set_bit & arr[i])
            x ^= arr[i];
        else
            y ^= arr[i];
    }

    for(int i = 1; i <= n; i++) {
        if(set_bit & i)
            x ^= i;
        else
            y ^= i;
    }
    cout << x << "  " << y << endl;
}

int main()
{
    int arr[] =  {4, 3, 6, 2, 1, 1};
    //int arr[] = {1, 3, 4, 5, 5, 6, 2};
    int n = ARRAY_SIZE(arr);

    find_missing_repeating(arr , n);

return 0;
}
