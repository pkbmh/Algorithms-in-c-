#include <bits/stdc++.h>
using namespace std;
int N;
vector < vector < int > >board;
int solution = 0;
void print_board() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			cout << board[i][j] << " ";
	
		cout << endl;
	}
}

bool can_place(int row , int col) {
	int i,j;
	//print_board();
	for(i = 0; i < col; i++)   //check in previous column ans same row //left side
 		if(board[row][i])
		return false;
	
	for(i = row , j = col; i >= 0 && j >= 0; i-- ,j--) //upper diagonal in leftside
		if(board[i][j])
		return false;
	
	for(i = row, j = col; i < N && j >= 0; i++, j--) //down diagonal in leftside
		if(board[i][j])
		return false;
	
	return true;
}
/*fundamental:	1	0	0	1	2	1	6	12	46	92	341	1,787	9,233	45,752	..	28,439,272,956,934	275,986,683,743,434	2,789,712,466,510,289
all:	1	0	0	2	10	4	40	92	352	724	2,680	14,200	73,712	365,596	..	227,514,171,973,736	2,207,893,435,808,352	22,317,699,616,364,044
*/

void place_queen(int col) {
	if(col == N) {
	solution++;
	return ;
	}

	for(int i = 0; i < N; i++) {
		if(can_place(i , col)) {
			board[i][col] = 1;
			place_queen(col+1);
			board[i][col] = 0;
		} 		
		 
	}
}
			
int main()
{
	int i , j;
	cin >> N;
	board.resize(N);
	
	for(i = 0; i < N; i++) {
		board[i].resize(N);
		for(j = 0; j < N; j++)
			board[i][j] = 0;
	}
	
	place_queen(0);
	
	cout << solution << endl;
	
return 0;
}
