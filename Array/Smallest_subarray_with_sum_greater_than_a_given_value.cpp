#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])
#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

/*
       while(end < n && sum <= x)
            sum += arr[end++];

        while(sum > x && start < end) {
            if(end-start < min_len)
                min_len = end-start;
            sum -= arr[start++];
        }
    }

*/
int minimum_length(int arr[] , int n ,int x) {
    int start,end;
    start = end = 0;
    int sum =  0;
    int min_len = n+1;
    int min = 99999;
    int low = 0, high = 0;

     while(start < n) {

            while (sum <= x && end < n){
                sum = sum + arr[end];
                end++;
            }

            if (sum >= x && sum < min) {
                min = sum;
                low = start;
                high = end;
            }
            sum = sum - arr[start];
            start++;
            }
        printf("%d with index start %d and end %d\n", min, low, high - 1);
    return high - low;
}
int main()
{
    int arr[] = {1, 11, 100, 1, 1, 200, 3, 2, 1, 250};
    int x = 280;
    int n = ARRAY_SIZE(arr);

    int len = minimum_length(arr , n , x);
    cout << "Minimum length of subarray is " << len << endl;

return 0;
}
