#include <bits/stdc++.h>
using namespace std;

vector < vector <int> >graph;
vector < int > path;
queue < int > vertex;
vector < bool >state;

int find_path_or_cycle(int pos , int v) {
	if(pos == n) {
	tr(graph[pos-1] , it) {
		if(*it == path[0])
		return 2;
	}
	
	return 1;
	}
	
	tr(graph[v] , it) {
		if(issafe(*it)) {
			path[pos] = *it;
			if(find_path_or_cycle(pos+1 , *it))
			return 2;
			else
			path[pos] = -1; //backtrack
		}
	}
	return 0;
}c
	
	
	
int main()
{	
	int n,i,j;
	
	scanf("%d" , &n);
	
	graph.resize(n);
	path.resize(n,-1);
	vertex.resize(n);
	state.resize(n,false);
	
	while(true) {
		cin >> u >> v;
		if(u == -1)
		break;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	path[0] = 0; //start from 0
	state[0] = 0;
	int ans = find_path_or_cycle(1,0);
	print(ans);
	
return 0;
}
