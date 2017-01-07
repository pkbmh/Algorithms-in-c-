#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;
#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

vector< vector<int> >graph;
queue<int>q;
bool state[10000];
vector<int>gen;

bool bipartite(int s) {
	gen[s] = 1;
	q.push(s);
	int v;
	while(!(q.empty())) {
		v = q.front();
		q.pop();
		state[v] = true;
		tr(graph[v] , it) {
			if(!state[*it]) {
				gen[*it] = 1-gen[v];
				q.push(*it);
			}
			else if(state[*it] && gen[*it] == gen[v])
				return false;
		}
	}
return true;
}				
	
		
int main()
{
	int i,v,s,d,n;
	bool result;
	scanf("%d", &n);
	
	graph.clear();
	gen.clear();
	graph.resize(n+1);
	gen.resize(n+1);
	
	for(i = 0; i <= n; i++)
		gen[i]  = -1;

	while(1){
		scanf("%d%d", &s,&d);
		if(s == -1)
		break;
		
		graph[s].push_back(d);
		graph[d].push_back(s);
	}
	memset(state , false , sizeof(state));
	result = true;
	for(i = 1; i <= n; i++) {
	if(!state[i])
	result = result & bipartite(1);
	if(!result){
	printf("Graph is not bipartite\n");
	break;
	}
	}
	if(result)
	printf("Graph is  bipartite\n");

	scanf("%d", &n);

return 0;
}
	