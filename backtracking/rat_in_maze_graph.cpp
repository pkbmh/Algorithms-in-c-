#include <bits/stdc++.h>
using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

vector < vector < int > >maze;
vector < bool > state;
vector < int > ans; 

bool go_out(int s , int d) {
	
	if(s == d)
	return true;
	
	state[s] = true;
	
	tr(maze[s] , it) {
		if(!state[*it]) {
			
			if(go_out(*it , d)) {
			ans.push_back(*it);
			return true;
			}
		}
	}
	return false;
}
		
int main()
{
	int i,d,s,v;
	cin >> v;
	
	maze.resize(v);
	state.resize(v , false);
	
	while(1) {
		cin >> s >> d;
		if(s == -1)
		break;
		
		maze[s].push_back(d);
		maze[d].push_back(s);
	}
	
	cin >> s >> d;
	
	if(go_out(s , d)) {
		ans.push_back(s);
		for(i = ans.size()-1 , cout << "path = "; i >= 0; i--)
			cout << ans[i] << " ";
	}
	else
		cout << "Solution not exits" << endl;
	
	cout << "\n";
return 0;
}
