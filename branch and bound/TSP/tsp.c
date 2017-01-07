#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#define max 100
int graph[max][max];
int n;
//int first_min[max];
//int second_min[max];
int visited[max];
int mincost = 100000;
int start;
int  s[10000];
int fans[10000];
int min(int a, int b) {

        return a < b ? a : b;
}

int allvisited() {
        int i;
        for (i = 0; i < n; i++) {
                if (visited[i] == 0)
                        return 0;
        }
        return 1;
}

int bound()
void tsp(int curr, int cost, int k) {
        int i  = 0;
        if (allvisited()) {
                cost += graph[start][curr];
                if (cost <= mincost)  {
                    mincost = cost;
                    
                for ( i = 0; i < n; i++)
                      fans[i]= s[i]; 
                } 
                fans[i] = fans[0];
        }
        for (i = 0; i < n; i++) {
                if (!visited[i]) {
                        visited[i] = 1;
                        s[k] = i;
                        tsp(i, cost + graph[curr][i], k + 1);
                        visited[i] = 0;
                }        
        
        }

}
 
int main() {

        scanf("%d", &n);
       int i, j;
       for (i = 0; i < n; i++) {
               for (j = 0; j < n; j++) {
                        graph[i][j] = 100000;
               }
       }
                
        while (true) {                
                int x , y , w;
                scanf("%d", &x);                
                
                if (x == -1) 
                        break;                
                
                scanf("%d%d", &y , &w);
                graph[x - 1][y - 1] = w;
                graph[y - 1][x - 1] = w;
       }
       

       for ( i = 0; i < n; i++) {
                memset(visited, 0, sizeof visited);
                start = i;
                visited[i] = 1;
                s[0] = i;
                tsp(i, 0, 1);         
       }
       
       printf ("%d\n", mincost);
       for (i = 0; i <= n; i++)
        printf ("%d ", fans[i] + 1);
        return 0;      
}
