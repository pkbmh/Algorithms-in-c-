#include <bits/stdc++.h>
using namespace std;
#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)


class GRAPH {
    int V;
    bool *visited;
    list < int > *vertex;
public:
    GRAPH(int a) {
        V = a;
        vertex = new list<int>[a];
        visited = new bool[a];
    }
    void insert_edge(int u , int v) {
        vertex[u].push_back(v);
    }
    void set_visited() {
       // memset(visited , false , sizeof(visited));
        //cout << " " << visited[V-1] << endl;;
        for(int i = 0; i < V; i++)
            visited[i] = false;
    }
    void DFS(int );
    void BFS(int );
};
void GRAPH::DFS(int s) {
    cout << s << " ";
    visited[s] = true;
    tr(vertex[s] , it)
        if(!visited[*it])
            DFS(*it);
}
void GRAPH::BFS(int s) {
    queue<int>qu;
    qu.push(s);
    visited[s] = true;
    while(!qu.empty()) {
        int v = qu.front();
        qu.pop();
        cout << v << " ";

        tr(vertex[v] , it)
            if(!visited[*it]) {
                qu.push(*it);
                visited[*it] = true;
            }
    }
}
int main()
{
    GRAPH g1(5); //graph of 5 vertex
    g1.insert_edge(0 , 1);
    g1.insert_edge(0 , 3);
    g1.insert_edge(0 , 4);
    g1.insert_edge(1 , 2);
    g1.insert_edge(1 , 3);
    g1.insert_edge(2 , 4);
    g1.insert_edge(2 , 1);
    g1.insert_edge(2 , 3);
    g1.insert_edge(3 , 0);
    g1.insert_edge(3 , 1);
    g1.insert_edge(3 , 2);
    g1.insert_edge(3 , 4);
    g1.insert_edge(4 , 0);
    g1.insert_edge(4 , 1);
    g1.insert_edge(4 , 2);
    g1.insert_edge(4 , 3);

    cout << "DFS result is (source 0)" << endl;
    g1.set_visited();
    g1.DFS(0);
    cout << endl;
    cout << "BFS result is (source 0)" << endl;
    g1.set_visited();
    g1.BFS(0);
    cout << endl;

return 0;
}
