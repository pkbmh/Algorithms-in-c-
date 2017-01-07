#include <bits/stdc++.h>
using namespace std;

int N;
vector < vector < int > >board;
void print_board() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			cout << board[i][j] << " ";
	
		cout << endl;
	}
}

bool can_place(int row , int col) {
	int i,j;
 
	for(i = 0; i < col; i++)   //check in previous column ans same row //left side
 		if(board[row][i])
		return false;
	
	for(i = row , j = col; i >= 0 && j >= 0; i-- ,j--) //upper diagonal in leftside
		if(board[i][j])
		return false;
	
	for(i = row, j = col; i < N && j >= 0; i++, j--) //down diagonal in left
		if(board[i][j])
		return false;
	
	return true;
}
bool place_queen(int col) {
	if(col >= N)
	return true;

	for(int i = 0; i < N; i++) {
		
		if(can_place(i , col)) {
			board[i][col] = 1;
		
			if(place_queen(col+1))
			return true;
			else board[i][col] = 0; //backtrack 
		}
	}
	return false;
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
	
	if(place_queen(0))
	print_board();
	
	else cout << "Can't place N queen" << endl;
	
return 0;
}
