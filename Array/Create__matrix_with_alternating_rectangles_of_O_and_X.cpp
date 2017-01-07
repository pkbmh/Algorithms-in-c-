/*
Write a code which inputs two numbers m and n and creates a matrix of size m x n (m rows and n columns)
in which every elements is either X or 0. The Xs and 0s must be filled alternatively,
the matrix should have outermost rectangle of Xs,then a rectangle of 0s, then a rectangle of Xs, and so on.
*/

#include <bits/stdc++.h>
using namespace std;

void fill_matrix(vector < vector < char > > &matrix , int row , int col )
{
    row -= 1;
    col -= 1;
    char symbol = 'X';
    for(int i = 0; i <= min(row , col)/2; i++) {

        int j = i;
        while(j <= col-i || j <= row-i) {
            if(j <= col-i) {
                matrix[i][j] = symbol;
                matrix[row-i][j] = symbol;
            }
            if(j <= row-i) {
                matrix[j][i] = symbol;
                matrix[j][col-i] = symbol;
            }
            j++;
        }
        symbol = (symbol == 'X') ? 'O' : 'X';
    }

}
int main()
{
    int row,col;
    vector < vector < char > > matrix;
    while(true) {
        cout << "Enter rows and column exit(-1 , -1)" << endl;
        cin >> row >> col;
        if(row == -1)
            break;
        matrix.clear();
        matrix.resize(row);
        for(int i = 0; i < row; i++)
            matrix[i].resize(col);

        fill_matrix(matrix , row , col);

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
return 0;
}
