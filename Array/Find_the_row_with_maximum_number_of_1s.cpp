#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

int first(bool arr[] , int l , int h) {
    if(l <= h) {

        int mid = (l+h)/2;

        if(arr[mid] == 1 && (mid-1 < 0 || arr[mid-1] == 0))
            return mid;
        else if(arr[mid] == 0 && (mid+1 > h || arr[mid+1] == 1))
            return mid+1;

        if(arr[mid] == 1)
            return first(arr , l , mid-1);
        else
            return first(arr , mid+1 , h);
    }
}
int maximum_1s_row(bool mat[R][C]) {
    int m;
    int pm = INT_MAX;
    int index;
    for(int i = 0; i < R; i++) {
        m = first(mat[i] , 0 , C-1);
      //  cout << m << "  i " << i << endl;
        if(m < pm) {
            index = i;
            pm = m;
        }
    }
    return index;
}
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},{0, 1, 1, 1},{1, 1, 1, 1},{0, 0, 0, 0} };

    int max_1row = maximum_1s_row(mat);

    cout << "Row with maximum 1" << endl;
    for(int i = 0; i < C; i++)
        cout << mat[max_1row][i] << " ";
    cout << endl;

return 0;
}
