#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
#define SIZEOF(str) sizeof(str)/sizeof(str[0])

int next_x[] = {-1 , -1  , -1 , 0 , 1 , 1 , 1 , 0};
int next_y[] = { -1,  0 , 1 , 1 , 1 , 0 , -1 , -1};

bool is_word(string *str , string word, int d_size) {
   for(int i= 0 ;i < d_size; i++) {
        if(word.compare(str[i]) == 0)
            return true;
   }
   return false;
}
void words_in_board(char board[R][C] ,bool visited[R][C] , string str[] ,int d_size ,  int x, int y , string word) {
    visited[x][y] = true;
    word += board[x][y];
      //  cout << word << endl;
    if(is_word(str , word , d_size))
        cout << word << endl;

    for(int i = 0; i < 8; i++) {
        int nx = x + next_x[i];
        int ny = y + next_y[i];

        if(nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny]) {
            words_in_board(board , visited , str ,d_size , nx , ny , word);
        }
    }

    word.erase(word.length()-1);
    visited[x][y] = false;
}
int main()
{
    string str[] = {"GEEKS", "FOR", "QUIZ", "GO"};
    int d_size = sizeof(str)/sizeof(str[0]);

    char board[R][C] = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

    bool visited[R][C];
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            visited[i][j] = false;

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            words_in_board(board ,visited , str ,d_size , i , j , "");
return 0;
}
