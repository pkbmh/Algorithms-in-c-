#include <bits/stdc++.h>
using namespace std;
#define R 6
#define C 5

void maximum_size_square(bool mat[R][C]) {
    int s[R][C];
    int i , j;

    for(i = 0; i < C; i++)
        s[0][i] = mat[0][i];

    for(i = 0; i < R; i++)
        s[i][0] = mat[i][0];


    for(i = 1; i < R; i++) {
        for(j = 1; j < C; j++) {
            if(mat[i][j] == 1)
                s[i][j] = min(s[i-1][j] , min(s[i][j-1] , s[i-1][j-1]))+1;
            else
                s[i][j] = 0;
        }
    }

    int max_s = s[0][0];
    int max_i , max_j;
    max_i = max_j = 0;

    for(i = 0; i < R; i++) {
        for(j = 0; j < C; j++) {
            if(max_s < s[i][j]) {
                max_s = s[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    for(i = max_i; i > max_i - max_s; i--) {
        for(j = max_j; j > max_j - max_s; j--) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
  bool mat[R][C] =  {{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};

    maximum_size_square(mat);

return 0;
}
