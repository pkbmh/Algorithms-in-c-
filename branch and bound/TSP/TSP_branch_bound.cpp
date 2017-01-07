#include <bits/stdc++.h>
using namespace std;
#define INF 999

vector <int>path;
int visit[100];
void print_graph(int v , int graph[][100])
{
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------------------------\n");
}

int row_reduce(int g[][100] , int v){
	int i,j;
	int lb = 0;
	for(i = 0; i < v; i++) {
		int min = INF;
		for(j = 0; j < v; j++) {
			if(min > g[i][j])
				min = g[i][j];
		}
			if(min != INF) {
				lb += min;
				for (j = 0; j < v; j++) {
					if(g[i][j] != INF)					
					g[i][j] -= min;
				}
		
			}
	}
return lb;
}
int column_reduce(int g[][100] , int v) {
	int i , j;
	int lb = 0;
	for(i = 0; i < v; i++) {
		int min = INF;
		for(j = 0; j < v; j++) {
			if(min > g[j][i])
				min = g[j][i];
		}
			if(min != INF) {
			lb += min;

				for (j = 0; j < v; j++) {
					if(g[j][i] != INF)
					g[j][i] -= min;
				}
		}
		
	}
return lb;
}

void make_g(int s , int i , int v , int graph[][100] , int g[][100]) {
	
	for(int k = 0; k < v; k++) {
		for(int l = 0; l < v; l++) {
			g[k][l] = graph[k][l];
		}
	}

	for(int k = 0; k < v; k++) {
		g[s][k] = INF;
		g[k][i] = INF;
	}
}

bool visited(int v) {
	for(int i = 0; i < v; i++) {
		if(!visit[i])
		return false;
	}
return true;
}

int find_next(int v) {
	for(int i = 0; i < v; i++) {
		if(visit[i])
		return i;
	}
}
void copy(int v , int graph[][100] , int g[][100])
{	
	for(int i = 0; i < v; i++) 
		for(int j = 0; j < v; j++)
			graph[i][j] = g[i][j];
}
int  solve(int s , int v , int lb , int graph[][100])
{	path.push_back(s);
	//cout << lb <<" apth "<<s <<endl;
	visit[s] = true;
	int i;
	int clb;
	int g[100][100];
	clb = INF;
	int nn = -1;;
	int tmp;
	//while(!visited(v)) {
		for(i = 0; i < v; i++) {
		//i = find_next(v);
			if(!visit[i]) {
			make_g(s,i ,v , graph, g);
			tmp = row_reduce(g , v);
			tmp += column_reduce(g , v);
			tmp += graph[s][i] + lb;		
				if(tmp < clb) {
					clb = tmp;
					nn = i;
				}
			}
		}
	
	if(nn == -1)
	return lb;

	make_g(s,nn ,v , graph, g);
	tmp = row_reduce(g , v);
	tmp += column_reduce(g , v);
	tmp += graph[s][nn] + lb;
	clb = tmp;
	//print_graph(v , g);
	//path.push_back(nn);
	copy(v , graph , g);
	//print_graph(v , g);
	//print_graph(v , graph);
	//cout << "tmp = " <<tmp<<" nn = "<<nn<<endl;
	solve(nn , v , clb , graph);
}
							
int main()
{
	int graph[100][100];
	memset(visit , false , sizeof(visit));
	int v,i,j,s,d,w;
	scanf("%d" , &v);

	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			graph[i][j] = INF;
		//	g[i][j]  = INF;
		}
	}

	while(true) {
			scanf("%d" ,&s);
			if(s == -1)
				break;
			scanf("%d%d" ,&d,&w);
			graph[s][d] = w;
	}
	/*for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			scanf("%d", &graph[i][j]);
		}
		graph[i][i] = INF;
	}*/
	
	int lb = row_reduce(graph,v);
	//print_graph(v);
	lb = lb + column_reduce(graph , v);
	//print_graph(v);
	
	int path_cost  = solve(0,v,lb,graph);	
	
	for(i = 0; i < path.size(); i++)
		cout << path[i] <<"->";
	
	cout << path[0];

	cout << endl;
	cout << "Path cost = " << path_cost << endl;

	//cout << lb;
	return 0;
}
