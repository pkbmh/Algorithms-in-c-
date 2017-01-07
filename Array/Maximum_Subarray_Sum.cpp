#include<bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int cross_sum(int arr[] , int l , int mid , int h) {
    int sum = 0;
    int left_sum,right_sum;
    left_sum = right_sum = INT_MIN;

    for(int i = mid; i >= l; i--) {
        sum += arr[i];
        if(sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    for(int i = mid+1; i <= h; i++) {
        sum += arr[i];
        if(sum > right_sum)
            right_sum = sum;
    }
    return (left_sum+right_sum);
}
int max_subarray_sum(int arr[] , int l , int h) {
    if(l == h)
        return arr[l];

    int mid = (l+h)/2;

    return max(max(max_subarray_sum(arr , l , mid) , max_subarray_sum(arr , mid+1 , h) ), cross_sum(arr , l , mid , h));
}
int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = ARRAY_SIZE(arr);

    int sum = max_subarray_sum(arr , 0 , n-1);
    cout << "Maximum subarray sum is " << sum << endl;

return 0;
}
