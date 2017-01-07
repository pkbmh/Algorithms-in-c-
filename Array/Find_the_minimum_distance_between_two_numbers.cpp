#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int minimum_distance(int arr[] , int x , int y , int n) {
    int ix ,iy;
    ix = iy = -1;
    int dis = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(arr[i] == x)
            ix = i;
        if(arr[i] == y)
            iy = i;

        if(ix != -1 && iy != -1)
            dis = min(abs(ix-iy) , dis);
    }
    return dis;
}
int main()
{
    int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3} , x = 3 , y = 6;
    //int  arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2;
    int n = ARRAY_SIZE(arr);

    int dist = minimum_distance(arr , x , y , n);

    cout << "Minimum distance is  " << dist << endl;

return 0;
}
