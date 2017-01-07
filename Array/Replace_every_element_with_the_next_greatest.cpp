#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int replace_with_next_greater(int arr[] , int n) {
    int max = arr[n-1];
    arr[n-1] = -1;
    int tmp;

    for(int i = n-2; i >= 0; i--) {
        tmp = max;
        if(arr[i] > max)
            tmp = arr[i];

        arr[i] = max;
        max = tmp;
    }
}
int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = ARRAY_SIZE(arr);

    replace_with_next_greater(arr , n);
    cout << "Output array is " << endl;

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

return 0;
}
