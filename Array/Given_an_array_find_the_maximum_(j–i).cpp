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
    int i = 0;
    int j = n-1;

    while(i < j) {
        if(arr[i] < arr[j])
            break;
        i++;
        j--;
    }
     if(i >= j)
        return -1;

    int left_move = i;
    int right_move = j;
    int len = 0;

    while(right_move < n-1 && arr[i] < arr[right_move+1])
        right_move++;

    while(left_move > 0 && arr[left_move-1] < arr[j])
        left_move--;

    //cout << " i " << i << " j " << j << " ri " << right_move << " li " << left_move << endl;
    //return  max((j-left_move) , (right_move-i));

    if((j-left_move) > (right_move-i)) {
        cout << " ( j = " << j << " , i = " << left_move << " ) "<< endl;
        return (j-left_move);
    }
    else {
        cout << " ( j = " << right_move << " , i = " << i << " )"<< endl;
        return (right_move-i);
    }

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
