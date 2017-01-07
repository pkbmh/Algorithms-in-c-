#include <bits/stdc++.h>
using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

vector < vector <int> > graph;
vector < int > color;

void print(void) {
	for(int i = 0; i < color.size(); i++)
		cout << "vertex = " << i << " color = " << color[i] << endl;
}

bool can_color(int s , int clr) {
	for(int i = 0; i < graph[s].size(); i++)
		if(color[graph[s][i]] == clr)
		return false;

	return true;
}

bool make_color(int m , int s , int n) {
	if(s == n)
	return true;
	
	for(int i = 1; i <= m; i++) {
		if(can_color(s , i)) {
			color[s] = i;
			if(make_color(m , s+1 , n))
				return true;
			else color[s] = -1;
		}
	}
	return false;	
}

int main()
{
	int i,n,j,m,u,v;
	cin >> n;
	
	graph.resize(n);
	color.resize(n , -1);

	while(true) {
		cin >> u;
		if(u == -1)
		break;
		cin >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	m = 1;
	while(1) {
		color.clear();
		if(make_color(m , 0 , n)) { 
			print();
			break;
		}
	
		
	m++;
	}
	cout << "minimum color need = "<<m<<endl; 
	//else
	//cout << "solution does not exist\n";
	
return 0;
}
