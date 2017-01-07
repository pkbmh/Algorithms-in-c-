/* Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
 Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
  Output: 6  (j = 7, i = 1)

  Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
  Output: 8 ( j = 8, i = 0)

  Input:  {1, 2, 3, 4, 5, 6}
  Output: 5  (j = 5, i = 0)

  Input:  {6, 5, 4, 3, 2, 1}
  Output: -1
  */
#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int find_maximum_ji(int arr[] , int n) {
    int *lmin = new int[n];
    int *rmax = new int[n];
    int i,j;

    lmin[0] = arr[0];
    for(i = 1; i < n; i++)
        lmin[i] = min(arr[i] , lmin[i-1]);

    rmax[n-1] = arr[n-1];
    for(i = n-2; i >= 0; i--)
        rmax[i] = max(arr[i] , rmax[i+1]);

    i = j = 0;
    int max_diff = -1;

    while(i < n && j < n) {
        if(lmin[i] < rmax[j]) {
            max_diff = max(max_diff , (j-i));
            j++;
        }
        else
            i++;
    }
    return max_diff;
}
int main()
{
    int arr[] = {9,8,7,6,5,10,1,1,1,1,1,1,1};
    //int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}; // 6
    //int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}; // 8;
    // int arr[] = {1, 2, 3, 4, 5, 6}; // 5;
    //int arr[] = {6, 5, 4, 3, 2, 1}; // -1;

    int n = ARRAY_SIZE(arr);

    int max_ji = find_maximum_ji(arr , n);
    cout << max_ji << endl;

return 0;
}

