#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 4

int main()
{
    //int size = max(ROW , COL);
    int matrix[100][100] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int tmp;

    cout << "Given matrix is " << endl;
    for(int i = 0; i < COL; i++) {
        for(int j = 0; j < ROW; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << "--------------------------------" << endl;
    // transpose of matrix.
    for(int i = 0; i < ROW; i++) {
        for(int j = i; j < COL; j++) {
            tmp  = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    // now reverse every row;

    for(int i = 0; i < COL; i++) {
        for(int j = 0; j < ROW/2; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][ROW-1-j];
            matrix[i][ROW-1-j] = tmp;
        }
    }

    // rotated matrix is
    for(int i = 0; i < COL; i++) {
        for(int j = 0; j < ROW; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
return 0;
}
