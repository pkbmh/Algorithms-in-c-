#include <bits/stdc++.h>
using namespace std;

void right_rotate(int arr[] , int n ,int  outplace , int cur) {

    int tmp = arr[cur];
    for (int i = cur; i > outplace; i--)
        arr[i] = arr[i-1];
    arr[outplace] = tmp;
}


void rearrange(int arr[] , int n) {
    int outplace = -1;

    for(int i = 0; i < n; i++) {
        if(outplace >= 0) {
            if((arr[i] >= 0 && arr[outplace] < 0) || (arr[i] < 0 && arr[outplace] >= 0))
            {
                right_rotate(arr , n , outplace , i);

                if(i - outplace > 2)
                    outplace += 2;
                else
                    outplace = -1;
            }
        }
        if(outplace == -1)
            if(((arr[i] >= 0) && !(i % 2)) || ((arr[i] < 0) && !(i % 2)))
                outplace = i;
    }
}

int main(){

    //int arr[n] = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
    //int arr[] = {-5, -3, -4, -5, -6, 2 , 8, 9, 1 , 4};
    int arr[] = {5, 3, 4, 2, 1, -2 , -8, -9, -1 , -4};
    //int arr[] = {-5, 3, -4, -7, -1, -2 , -8, -9, 1 , -4};
    //int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Before rearrange array is " << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    rearrange(arr , n);

    cout << "After rearrange array is " << endl;
     for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

return 0;
}
