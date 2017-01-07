#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include "heap.h"

using namespace std;

#define max 999999
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef pair <int , int > pp;

typedef struct t {
int edge ;
int cost;
t(int x , int y) {
edge = x;
cost = y;
}
}t;

vector <int > d;
vector <vector < t > > graph;
bool visited[max];
vector < pp > answer ;

void prims(int pq[][2] , int n , int index[]) {
      
    int i = 1;
    int tn = n;
    while (i <= tn ) {
       
	   	pp z = extract_min(pq , n , index);
	   	visited[i] = true;
	 	printf ("%d %d\n", z.second , z.first);   
		i++;
			
		for (int j = 0; j < graph[z.second].size(); j++) {
	
		if (!visited[graph[z.second][j].edge] && d[graph[z.second][j].edge] > graph[z.second][j].cost) {		
			d[graph[z.second][j].edge] = graph[z.second][j].cost ;
			decrease_key(pq , index[graph[z.second][j].edge] , d[graph[z.second][j].edge] , index);
			}
		}
	}
}

int main() {
 
	int n , m , x , y , z;
	 
	scanf("%d%d", &n, &m);
	
	graph.resize(n + 1);
	d.resize(n+1);
	
	int index[n+1];
	int pq[n+1][2];

	for (int i = 0; i < m; i++) {
	
		scanf("%d%d%d", &x, &y, &z);
		graph[x].push_back(t(y , z));
		graph[y].push_back(t(x , z));
	
	}


	for (int i = 1; i <= n; i++) {
		d[i] = 99999;
		index[i] = i;
		pq[i][0] = 99999;
		pq[i][1] = i;
	}
	
	d[1] = 0;
	pq[1][0] = 0;

	build_min_heap(pq , n , index);

	prims(pq , n , index);
		 
	return 0;
}
