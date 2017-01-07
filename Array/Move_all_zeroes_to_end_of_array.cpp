#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

void move_zeros_to_end(int arr[] , int n) {
    int i = 0;
    int j = 0;

    while(j  < n) {
        if(arr[i] > 0){
            i++;
            j++;
        }
        else {
            if(arr[j] != 0){
                arr[i] = arr[j];
                arr[j] = 0;
                i++;
                j++;
            }
            else
                j++;
        }
    }
}

void move_zeros_to_end1(int arr[] , int n) {
    int c = 0;
    for(int  i = 0 ; i < n; i++)
        if(arr[i] != 0)
            arr[c++] = arr[i];

    while(c < n)
        arr[c++] = 0;
}
int main()
{
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    int n = ARRAY_SIZE(arr);

    move_zeros_to_end1(arr , n);
    cout << "Modified Array is " << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

return 0;
}
