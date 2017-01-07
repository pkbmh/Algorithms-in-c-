#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

void max_sum_subarray(int arr[] , int n) {
    int cur_max = 0;
    int max = 0;
    int start , end;
    start = end = 0;

    for(int i = 0; i < n; i++) {
            cur_max += arr[i];
        if(cur_max < 0) {
            cur_max = 0;
        }
        else if(cur_max > max){
            max = cur_max;
            start = end;
            end = i;
        }
    }
    cout << "maximum subarray sum is :: " << max << " from index " << start << " to " << end << endl;
}
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = ARRAY_SIZE(arr);

    max_sum_subarray(arr, n);

return 0;
}
