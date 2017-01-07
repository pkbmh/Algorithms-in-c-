#include <bits/stdc++.h>

using namespace std;

typedef struct graph_detail {
	int p;
	int s;
	int d;
	int c;
}graph;

vector<graph>g_detail;
vector<graph>rg_detail;

vector<vector<int> >g;
vector<vector<int> >rg;

bool state[10000];
queue<int>q;
vector<int>parent;

bool bfs(int s , int d) {
	memset(state , false , sizeof(state));
	
	int size = rg[s].size();
	parent.clear();
	parent.resize(size);
	q.push(s);
	while(!(q.empty())) {
		int v = q.front();
		state[v] = true;
		q.pop();
		for(int i = 0; i < size; i++) {
			if(!state[i] && (rg[v][i] > 0)) {
				q.push(i);
				state[i] = true;
				parent[i] = v;
			}
		}
	}
	if(state[d])
	return true;
	
return false;
}
		
				
int ford_fulkerson(int s , int d) {
	//cout<<s<<" "<<d<<endl;	
	int max_flow = 0;
	int i;
	while(bfs(s , d)){
		int flow = INT_MAX;
		i = d;
		while(i != s) {
			int u = parent[i];
			flow = min(flow  , rg[u][i]);
			i = u;
		}
		i = d;
		while(i != s) {
			int v = parent[i];
			rg[v][i] -= flow;
			rg[i][v] += flow;
			i = v;
		}
		max_flow += flow;
	}
return max_flow;
}

int main()
{
	int n,s,d,c;
	scanf("%d", &n);
	
	g.clear();
	rg.clear();
	g.resize(n+1);
	rg.resize(n+1);
	
	for(int i = 0; i <= n; i++) {
		g[i].resize(n+1);
		rg[i].resize(n+1);
	}
	
	
	while(1){
		scanf("%d%d%d", &s,&d,&c);
		
		if(s == -1)
		break;
		//cout<<s<<d<<c<<endl;
		g[s][d] = rg[s][d] = c;
	}
	int start , dist;
	scanf("%d%d", &start , &dist);
	
	int max_flow = ford_fulkerson(start , dist);
	
	printf("Flowing network graph\n");
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(g[i][j] != 0)
			cout<<g[i][j]-rg[i][j]<<" ";
			else cout<<"0"<<" ";
		}
		cout<<endl;
	}
	
	printf("Maximum flow is = %d\n", max_flow);
return 0;
}
