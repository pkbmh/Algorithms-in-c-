#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int longest_bitonic(int arr[] , int n) {
    int *lis , *lds;
    lis = new int[n];
    lds = new int[n];

    for(int i = 0; i < n; i++)
        lis[i] = lds[i] = 1;

    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j] && lis[i] < lis[j]+1)
                lis[i] = lis[j]+1;

    for(int i = n-2; i >= 0; i--)
        for(int j = n-1; j > i; j--)
            if(arr[i] > arr[j] && lds[i] < lds[j]+1)
                lds[i] = lds[j]+1;

    int max = INT_MIN;
    for(int i = 0; i < n; i++)
        if(max < lis[i]+lds[i]-1)
            max = lis[i]+lds[i]-1;

    return max;

}
int main()
{
    //int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    //int arr[] = {12, 11, 40, 5, 3, 1};
    int arr[] = {80, 60, 30, 40, 20, 10};
    int n = ARRAY_SIZE(arr);

    int len = longest_bitonic(arr , n);
    cout << "Length of Longest Bitonic Subsequence is  " << len << endl;

return 0;
}
