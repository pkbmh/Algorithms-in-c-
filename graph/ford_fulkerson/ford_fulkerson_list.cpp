#include <bits/stdc++.h>

using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef  struct child_parent {
	int p;
	int c;
	int ind;
}cp;

typedef pair<int , int>pii;
typedef vector<pii>vpii;

vector<vpii> g;
vector<vpii> rg;

vector<cp>ch_pa;

bool state[10000];
queue<int>q;
bool bfs(int s , int d) {
	memset(state , false , sizeof(state));
	
	ch_pa.clear();
	ch_pa.resize(g.size());
	q.push(s);
	while(!(q.empty())) {
		int v = q.front();
		state[v] = true;
		q.pop();
		int i = 0;
		tr(rg[v] , it) {
		
			if(!state[it->first] && (it->second > 0)) {
				q.push(it->first);
				state[it->first] = true;
				
				
				ch_pa[it->first].ind = i;
				ch_pa[it->first].p = v;
				ch_pa[it->first].c = it->second;
				i++;
				
			}
			else if(state[it->first] && (it->second > 0)) {
			i++;
			}
		}
	}
	if(state[d])
	return true;
	
return false;
}
int ford_fulkerson(int s , int d) {	
	int max_flow = 0;
	int i;
	while(bfs(s , d)){
		int flow = INT_MAX;
		i = d;
		while(i != s) {
			 int c = ch_pa[i].c;
			int u = ch_pa[i].p;
			int ind = ch_pa[i].ind;
			flow = min(flow , c);
			 i = u;
		}
		i = d;
		while(i != s) {
			int ind = ch_pa[i].ind;
			 int p = ch_pa[i].p;
 
			 rg[p][ind].second -= flow;
			 i = p;
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
	
	
	while(1){
		scanf("%d%d%d", &s,&d,&c);
		
		if(s == -1)
		break;
		g[s].push_back(make_pair(d , c));
		rg[s].push_back(make_pair(d , c));
	}
	int start , dist;
	scanf("%d%d", &start , &dist);
	
	int max_flow = ford_fulkerson(start , dist);
	printf("Maximum flow is = %d\n", max_flow);
return 0;
}
