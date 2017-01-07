#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int max_product(int arr[] , int n) {
    int max_end = arr[0];
    int max_pro = arr[0];

    for(int i = 1; i < n; i++) {
        max_end *= arr[i];
        if(arr[i] == 0)
            max_end = 1;
        if(max_end > max_pro)
            max_pro = max_end;
    }
    return max_pro;
}
int main()
{
    // int arr[] = {6, -3, -10, 0, 2}; // = 180
    //int arr[] = {-1, -3, -10, 0, 60}; // = 60 ,
    //int arr[] = {-2, -3, 0, -2, -40}; // = 80
   // int arr[] = {1, -2, -3, 0, 7, -8, -2}; //112
    int arr[] = {1 , 3 , -1 , 0 , -1 , 3};
    int n = ARRAY_SIZE(arr);

    int product = max_product(arr , n);
    cout << "Maximum product of subarray is " << product << endl;

return 0;
}
