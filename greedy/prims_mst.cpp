#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>mst;
int graph[100][100];

typedef struct node {
	int v;
	int p;
	int w;
	bool state;
}q;
vector<q>info;
int min_w() {	
	int min = INT_MAX;
	int ind;
	for(int i = 1; i <= n; i++) {
		if(info[i].w < min && info[i].state == false) {
			min = info[i].w;
			ind = info[i].v;
		}
	}
return ind;
}

void prims(int s) {
	int i,j;
	info[s].w = 0;
	info[s].p = -1;
	for(i = 1; i <= n; i++) {
		int v = min_w();
		mst.push_back(v);
		info[v].state = true;
		for(j = 1; j <= n; j++) {
			if((graph[v][j] != -1) && (info[j].w > graph[v][j]) && (info[j].state == false)) {
				info[j].w = graph[v][j];
				info[j].p = v;
			}
		}
	}
}

int main()
{
	int i,j,u,v,tw;	
	scanf("%d", &n);
	//int graph[n+1][n+1];
	mst.clear();
	info.resize(n+1);	
	for(i = 0; i <= n; i++)
		for(j = 0; j <= n; j++)
			graph[i][j] = -1;


	//memset(state , false , sizeof(state));
	//memset(graph , INT_MAX , sizeof(graph[0][0])*(n+1)*(n+1));
	while(1){
		scanf("%d%d%d", &u,&v,&tw);
		if(u == -1)
		break;
		u += 1;
		v += 1;
		graph[u][v] = tw;
		graph[v][u] = tw;
	}
	
	for(i = 1; i <= n; i++) {
		info[i].v = i;
		info[i].p = -1;
		info[i].state = false;
		info[i].w = INT_MAX;
	}
	prims(1);
	
	printf("Printing sequence of visiting node\n");
	for(i = 0; i < mst.size(); i++)
		printf("%d ", mst[i]);
	
	printf("\n\n");
	
	int weight = 0;
	for(i = 1; i <= n; i++) {
		printf("Node %d visited by Node %d\n", info[i].v , info[i].p);
		weight = weight + info[i].w;
	}
	printf("\n");
	printf("weight of tree = %d\n", weight);
return 0;
}
