#include <bits/stdc++.h>
using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define PII pair<int,int>

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
    bool check_bipartite();
    bool check_bipartite_util(int  , int *);
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

bool GRAPH::check_bipartite_util(int s , int *gender){
    queue<int>qu;
    qu.push(s);
    visited[s] = true;
    while(!qu.empty()) {
        s = qu.front();
        qu.pop();
        tr(vertex[s] , it) {
            if(!visited[*it]) {
                visited[*it] = true;
                gender[*it] = 1-gender[s];
                qu.push(*it);
            }
            else if(gender[s] == gender[*it])
                return false;
        }
    }
    return true;
}
bool GRAPH::check_bipartite(){
    set_visited();
    int gender[V];

    memset(gender , 1 , sizeof(gender));

    for(int i = 0; i < V; i++)
        if(!visited[i])
          if(!check_bipartite_util(i , gender))
            return false;


    return true;
}
int main()
{
   GRAPH g(5);
   g.insert_edge(0 , 1);
   g.insert_edge(0 , 3);
   g.insert_edge(0 , 4);
   g.insert_edge(1 , 2);
   g.insert_edge(3 , 2);
   g.insert_edge(2 , 4);
   g.insert_edge(1 , 3);
   //g.insert_edge()
   bool res = g.check_bipartite();
   if(res == true)
    cout << "Graph is bipartite " << endl;
   else
    cout << "Graph is not bipartite " << endl;

return 0;
}
