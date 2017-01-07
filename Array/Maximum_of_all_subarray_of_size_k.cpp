#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

void maximum_of_subarray(int arr[] , int n , int k) {
    deque < int > qu;
    int i;
    for(i = 0; i < k; i++) {
        while(!qu.empty() && arr[i] >= arr[qu.back()])
            qu.pop_back();

        qu.push_back(i);
    }

    for(; i < n; i++) {
        cout << arr[qu.front()] << " ";

        while(!qu.empty() && qu.front() <= i-k)
            qu.pop_front();

        while(!qu.empty() && arr[i] >= arr[qu.back()])
            qu.pop_back();

        qu.push_back(i);
    }
    cout << arr[qu.front()] << endl;
}
int main()
{
    int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int n = ARRAY_SIZE(arr);
    int k = 3;

    maximum_of_subarray(arr,  n , k);

return 0;
}
