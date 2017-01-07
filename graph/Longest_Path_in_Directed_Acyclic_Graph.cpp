#include <bits/stdc++.h>
using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define PII pair <int , int>

class GRAPH{
    int V;
    list < PII > *vertex;
    bool *visited;
public:
    GRAPH(int a) {
        V = a;
        vertex = new list<PII>[a];
        visited = new bool[a];
    }
    void insert_edge(int s , int d , int w) {
        vertex[s].push_back(make_pair(d , w));
    }
    void topological_sort_util(int s , stack<int>&st);
    void topological_sort(int );
    void longest_path(int source , stack<int>&st);
};
void GRAPH::topological_sort_util(int s , stack<int>&st) {
    visited[s] = true;
   // st.push(s);

    tr(vertex[s] , it) {
        if(!visited[it->first])
            topological_sort_util(it->first , st);
    }
    st.push(s);
}
void GRAPH::topological_sort(int source) {
    stack<int>st;
    for(int i = 0; i < V; i++)
        if(!visited[i])
            topological_sort_util(i , st);

    longest_path(source , st);
}
void GRAPH::longest_path(int source , stack<int>&st) {
    int *dist = new int[V];
    for(int i = 0; i < V; i++)
        dist[i] = INT_MIN;
    dist[source] = 0;

    while(!st.empty()) {
        int v = st.top();
        st.pop();
        if(dist[v] != INT_MIN)
            tr(vertex[v] , it)
                dist[it->first] = max(dist[it->first] , dist[v]+it->second);
    }

    cout << "Longest path from 1 " << endl;
    for(int i = 0; i < V; i++)
        (dist[i] == INT_MIN) ? cout << " INF " << " " : cout << dist[i] << " ";
}
int main()
{
    GRAPH g(6);
    g.insert_edge(0, 1, 5);
    g.insert_edge(0, 2, 3);
    g.insert_edge(1, 3, 6);
    g.insert_edge(1, 2, 2);
    g.insert_edge(2, 4, 4);
    g.insert_edge(2, 5, 2);
    g.insert_edge(2, 3, 7);
    g.insert_edge(3, 5, 1);
    g.insert_edge(3, 4, -1);
    g.insert_edge(4, 5, -2);

    int source = 1;
    g.topological_sort(source);

return 0;
}
