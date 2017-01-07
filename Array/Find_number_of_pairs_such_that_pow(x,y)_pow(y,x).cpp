#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int find_next_max(int x , int Y[], int l , int h) {
    if(l > h)
        return l;
    if(l == h && x < Y[h])
        return l;
    if(Y[l] > x)
        return l;

    int mid = (l+h)/2;

    if(Y[mid] > x)
        return mid;
    if(Y[mid] <= x)
        return find_next_max(x , Y , mid+1 , h);
    else
        return find_next_max(x , Y , l , mid-1);

}
int count_for_this(int x , int Y[], int sizey , int noy[]) {
    if(x == 0)
        return 0;
    if(x == 1)
        return noy[0];

    int total_pair = 0;
    int index = find_next_max(x , Y , 0 , sizey-1);
        total_pair = sizey-index;

    total_pair += noy[0] + noy[1];

    if(x == 2)
        total_pair -= noy[3]+noy[4];

    if(x == 3)
        total_pair += noy[2];

    return total_pair;
}
int count_pair(int X[] , int sizex , int Y[] , int sizey) {
    int noy[5] = {0};

    sort(Y , Y+sizey);
    for(int i = 0; i < sizey && Y[i] < 5; i++)
        noy[Y[i]]++;

    int total_pair = 0;
    for(int i = 0; i < sizex; i++)
        total_pair += count_for_this(X[i] , Y , sizey , noy);

    return total_pair;
}
int main()
{
    int X[] = {10, 19, 18};
    int Y[] = {11, 15, 9};
    int sizex = ARRAY_SIZE(X);
    int sizey = ARRAY_SIZE(Y);

    int total_pair = count_pair(X , sizex , Y , sizey);
    cout << "Number of total pair is = " << total_pair << endl;

return 0;
}
