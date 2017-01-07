#include <bits/stdc++.h>
using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

vector < vector < int > >maze;
vector < bool > state;
vector < pair<int , int> > ans; 
int v;

bool in_matrix_path(int nx , int ny) {
	if(nx >= 0 && nx < v && ny >= 0 && ny < v && maze[nx][ny] == 1)
	return true;
	
	return false;
} 

bool go_out(int sx , int sy ,int dx , int dy , int next_x[] , int next_y[]) {
	if(sx == dx && sy == dy)
	return true;
	
	maze[sx][sy] = 0;
	for(int i = 0; i < 4; i++) {
		int nx = sx + next_x[i];
		int ny = sy + next_y[i];
		
		if(in_matrix_path(nx , ny)) {
			if(go_out(nx , ny , dx , dy , next_x , next_y)) {
			ans.push_back(make_pair(nx , ny));
			maze[nx][ny] = 0;
			return true;
			}
			//maze[nx][ny] = 0;
			//else maze[nx][ny] = 1;
		}
	}
return false;
}
		
int main()
{
	int j,i,d,s;
	cin >> v;
	
	maze.resize(v);
	state.resize(v , false);
	
	for(i = 0; i < v; i++) {
		maze[i].resize(v);
		for(j = 0; j < v; j++)
			cin >> maze[i][j];
	}
	int sx,sy,dx,dy;
	cout<< "enter coordinate of start end exit point\n";
	
	cin >> sx >> sy >> dx >> dy;
	
	int next_x[4] = {-1 , 0 , 1 , 0};
	int next_y[4] = {0 , 1 , 0 , -1};
	
	if(go_out(sx , sy , dx , dy , next_x , next_y)) {
		ans.push_back(make_pair(sx , sy));
		for(i = ans.size()-1 , cout << "path = "; i >= 0; i--)
			cout << ans[i].first << " " << ans[i].second << endl;
	}
	else
		cout << "Solution not exits" << endl;
	
	cout << "\n";
return 0;
}
