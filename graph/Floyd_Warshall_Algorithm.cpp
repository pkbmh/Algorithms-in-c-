#include <bits/stdc++.h>
using namespace std;

int **floyd_warshall(int **graph , int v) {

    int **result;
    result = (int **)malloc(sizeof(int *)*v);
    for(int  i = 0; i < v; i++)
        result[i] = (int *)malloc(sizeof(int)*v);


    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            result[i][j] = graph[i][j];

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            for(int k = 0; k < v; k++) {
                if(result[i][k] != INT_MAX && result[k][j] != INT_MAX)
                    result[i][j] = min(result[i][k]+result[k][j] , result[i][j]);
            }
        }
    }
    return result;
}
void print_result(int **result , int v) {
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (result[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf ("%7d", result[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int v = 4;
    int s,d,w;
    int **graph;
    graph = (int **)malloc(sizeof(int *)*v);
    for(int i = 0; i < v; i++)
        graph[i] = (int *)malloc(sizeof(int)*v);

    for(int i = 0; i < v; i++)
        for(int j= 0; j < v; j++)
            graph[i][j] = INT_MAX;
    for(int i = 0; i < v; i++)
        graph[i][i] = 0;

    FILE *fp = fopen("input_floyd_warshall.txt","r");
    while((fscanf(fp , "%d %d %d" , &s , &d , &w)) != EOF)
        graph[s][d] = w;

    int **result = floyd_warshall(graph , v);
    print_result(result , v);

return 0;
}
