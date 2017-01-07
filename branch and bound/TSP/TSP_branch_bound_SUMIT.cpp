#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <time.h>

#define max 1000

using namespace std;

int cnt = 0;
int min1[max];
int min2[max];
int n;
int mat[max][max];
int best_path[max];
int mi = 99999;

int tsp(int level , int path[] , int E , int C_min , int sum , bool vis[]) {

	if ( level == n - 1) {
		if (sum + mat[path[level]][0] < C_min) {
			C_min = sum + mat[path[level]][0] ;
			for (int i = 0; i < n; i++) {
			best_path[i] = path[i];
			printf("%d ", best_path[i]);
			}
		}
	//printf("yes %d\n", sum + mat[path[level]][0]);
	return C_min;
	}

	for (int i = 1; i < n; i++) {
		
		if (!vis[i]) {
			if (sum + mat[path[level]][i] + ( E - min1[path[level]] - min2[path[level]] ) / 2 < C_min) {
				vis[i] = true;
				path[level + 1] = i;
				C_min = tsp(level + 1 , path ,  E - min1[path[level]] - min2[path[level]] , C_min ,  sum + mat[path[level]][i] , vis);
				vis[i] = false;
				}
			}
	}
return C_min;
}


int main()
{
	
	scanf("%d", &n);
	bool vis[n];
	int path[n+1];
	for (int i = 0; i < n; i++)
		vis[i] = false;
	
//	cout << "Input the distance matrix" << endl;

	

	for (int i = 0; i < n; i++) {
		mat[i][i] = 0;
		for (int j = 0; j < n; j++) {
			
			scanf("%d", &mat[i][j]);
	//printf("%d ", mat[j][i]);
		}
		//printf("\n");
	}
	
	for (int i = 0; i < n; i++) {
	
		for (int  j= 0; j < n; j++) {
			printf("%d ", mat[i][j]);
		}
	printf("\n");
	}
		
	
	clock_t strt = clock();
	int wmin = 0;
	
	int lb = 0;

	for (int i = 0; i < n; i++) {
		min1[i] = INT_MAX;
		
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (mat[i][j] <= min1[i]) {
					min2[i] = min1[i];
					min1[i] = mat[i][j];
				} else if (mat[i][j] < min2[i])
					min2[i] = mat[i][j];
			}
		}
		lb += min1[i] + min2[i];
	}

	int i = 0;
	int done = n;
	cnt = 1;
	best_path[0] = 0;
	int k = 1;
	while (--done) {
		vis[i] = true;
		int idx;
		int mx = INT_MAX;
		for (int j = 1; j < n; j++) {
			if (!vis[j] && mat[i][j] < mx) {
				idx = j;
				mx = mat[i][j];
				
			}
		}
		wmin += mx;
		i = idx;
		best_path[k++] = idx;
	}

	wmin += mat[i][0];

	for (int i = 1; i < n; i++)
		vis[i] = false;
	
	path[0] = 0;
	vis[0] = true;
	printf("%d\n", wmin);
	printf("%d\n", tsp(0 , path , lb , wmin , 0 , vis));
	
	for (int i = 0; i < n; i++)
	printf("%d ",best_path[i]); 
	return 0;
}
	
