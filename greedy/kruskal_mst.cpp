#include <bits/stdc++.h>
using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef pair<int , int>pii;
typedef vector< pii >vpii;
vector< pair< int  , pii > >graph;
vector< pair< int  , pii > >mst;
int v;
vector<int>parent;

int find_parent(int u) {
	if(u == parent[u])
		return u;
	find_parent(parent[u]);
}
int  kruskal() {
	
	sort(graph.begin() , graph.end());
	int mst_cost = 0;
	int pick_edge = 1;
	int i = 0;
	int s,d,ps,pd;
	while(pick_edge < v) {
		s = graph[i].second.first;
		d = graph[i].second.second;
		ps = find_parent(s);
		pd = find_parent(d);
		
		if(ps != pd) {
			mst.push_back(graph[i]);
			pick_edge++;
			parent[pd] = ps;
			mst_cost += graph[i].first;
		}
		i++;
	}
	
	return mst_cost;
} 
		
int main()
{
	int s, d, w;
	scanf("%d", &v);
	
	parent.resize(v);
	
	for(int i = 0; i < v; i++)
		parent[i] = i;
	
	while(1) {
		scanf("%d %d %d", &s , &d , &w);
		if(s == -1)
		break;
		
		graph.push_back(make_pair(w , make_pair(s , d)));
		graph.push_back(make_pair(w , make_pair(d , s)));
	}
	
	
	int mst_cost = kruskal();
	cout << "cost of mst is  = " << mst_cost << endl;
	
	int size = mst.size();
	cout << "Edge's in mst \n";
	
	for(int i = 0; i < size; i++)
		cout<<mst[i].second.first<<"->"<<mst[i].second.second<<" "<<mst[i].first<<endl;
	
return 0;
}
