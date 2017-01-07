#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

void Find_subarray(int arr[] , int n , int sum) {
    int cur_sum = 0;
    int start = 0;

    for(int i = 0; i < n; i++) {

        while(start < i && cur_sum > sum) {
            cur_sum -= arr[start];
            start++;
        }
        if(cur_sum == sum){
            cout << "Subarray is from " << start << " to " << (i-1) <<endl;
            return;
        }
        cur_sum += arr[i];
    }
}
int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = ARRAY_SIZE(arr);
    int sum = 33;

    Find_subarray(arr , n , sum);

return 0;
}
