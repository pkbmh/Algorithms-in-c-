#include <bits/stdc++.h>
using namespace std;

void topological_sort(int **graph ,int v , int s ,int *topological_rank  , bool *visited){
    static int t = 0;
    visited[s] = true;

    for(int i = 0; i < v; i++) {
        if(graph[s][i] && !visited[i]) {
            topological_sort(graph , v , i , topological_rank , visited);
        }
    }
    topological_rank[s] = t++;

}
int main()
{
    int v = 6;
    int **graph = new int *[v];
    for(int i = 0; i < v; i++)
        graph[i] = new int[v];

    for(int i = 0; i < v; i++)
        for(int j = 0; j  < v; j++)
            graph[i][j] = 0;

    FILE *fp = fopen("input_Assign_direction.txt" , "r");
    int i,j;
    while((fscanf(fp , "%d %d" , &i , &j)) != EOF)
        graph[i][j] = 1;


    cout << "Input graph is " << endl;
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    int *topological_rank = new int[v];
    bool visited[v];
    memset(visited , false , sizeof(visited));

    topological_sort(graph , v , 0 , topological_rank , visited);

    for(int i = 0; i < v; i++)
        cout << i << " : " << topological_rank[i] << endl;

return 0;
}
