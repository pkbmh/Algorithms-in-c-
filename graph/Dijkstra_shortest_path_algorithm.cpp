#include <bits/stdc++.h>
using namespace std;
#define PII pair <int , int>
#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)


template<class x>void swaper(x &a , x &b) { x t = a; a = b; b = t; }

class GRAPH {
    int v;
    list< PII >*vertex;
public:
    GRAPH(int a) {
        v = a;
        vertex = new list<PII>[a];
    }
    void insert_edge(int s,  int d , int w) { vertex[s].push_back(make_pair(d ,w)); }
    void Dijkstra_shortest_path(int );
    void print();
};

void GRAPH::print() {
    for(int i = 0; i < v; i++) {
        cout << i << "-> ";
        tr(vertex[i] , it) {
            cout << "(" << it->first << " : " << it->second << ") -> ";
        }
        cout << " NULL " << endl;
    }
    cout << endl;
}
void GRAPH::Dijkstra_shortest_path(int s) {
    vector<int>dist(v , INT_MAX);
    vector<int>parent(v , -1);
    vector<bool>visited(v,false);

    set<PII>pq;
    for(int i = 1; i < v; i++)
        pq.insert(make_pair(dist[i] , i));

    pq.insert(make_pair(0 , 0));
    dist[0] = 0;

    while(!pq.empty()) {
        PII tmp = *pq.begin();
        pq.erase(pq.begin());
        visited[tmp.second] = true;
        tr(vertex[tmp.second] , it) {
            if(!visited[it->first] && dist[it->first] > dist[tmp.second]+it->second) {
                pq.erase(pq.find(make_pair(dist[it->first] , it->first)));
                pq.insert(make_pair(dist[tmp.second]+it->second , it->first));
                dist[it->first] = dist[tmp.second]+it->second;
                parent[it->first] = tmp.second;
            }
        }
    }
    cout << "Distance from source " << s << endl;
    cout << "vertex   :  parent   : distance " << endl;
    for(int i = 0; i < v; i++) {
         cout << "      " << i << "  :   "  <<parent[i]  << "    : " << dist[i] << endl;
    }
}

int main()
{
    GRAPH graph(9);
    FILE *fp = fopen("input_dijkstra.txt" , "r");
    int s,d,w;
    while((fscanf(fp , "%d %d %d" , &s , &d , &w)) != EOF){
        graph.insert_edge(s , d , w);
        graph.insert_edge(d , s , w);
    }

   // graph.print();
    s = 0;
   graph.Dijkstra_shortest_path(s);

return 0;
}
