/*
Input: a[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 (12 + 8 - 8 + 9 - 9 + 10)

Input: a[] = {10, -3, -4, 7, 6, 5, -4, -1}
Output:  23 (7 + 6 + 5 - 4 -1 + 10)

Input: a[] = {-1, 40, -14, 7, 6, 5, -4, -1}
Output: 52 (7 + 6 + 5 - 4 - 1 - 1 + 40)
*/
#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int kadane_sum(int arr[] , int n) {
    int max_sum = 0;
    int cur_sum = 0;

    for(int i = 0; i < n; i++) {
        cur_sum += arr[i];
        if(cur_sum < 0)
            cur_sum = 0;
        else if(cur_sum > max_sum)
            max_sum = cur_sum;
    }
    return max_sum;
}

int maximum_circular_sum(int arr[] , int n) {
    int csum = kadane_sum(arr , n);

    int max_warp = 0;
    for(int i = 0; i < n; i++) {
        max_warp += arr[i];
        arr[i] = -arr[i];
    }

    max_warp += kadane_sum(arr , n);

    return max(max_warp , csum);
}

int main()
{
    int arr[] =  {8, -8, 9, -9, 10, -11, 12};
    int n = ARRAY_SIZE(arr);

    int csum = maximum_circular_sum(arr , n);
    cout << "Maximum circular sum is " << csum << endl;

return 0;
}
