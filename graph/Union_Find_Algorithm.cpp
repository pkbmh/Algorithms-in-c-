#include <bits/stdc++.h>
using namespace std;
#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define PII pair<int , int>

typedef struct PARENT_RANK {
    int s;
    int rank;
}PARENT_RANK;

class GRAPH {
    int V;
    vector < PII >edges;
public:
    GRAPH(int a) {V = a;}
    void insert_edge(int s , int d) {edges.push_back(make_pair(s , d)); }
    void make_union(PARENT_RANK &p1 , PARENT_RANK &p2);
    void union_find();
    int find_parent(PARENT_RANK *parent , int s);
};
void GRAPH::union_find() {
    PARENT_RANK *parent = new PARENT_RANK[V];

    for(int i = 0; i < V; i++) {
        parent[i].s = i;
        parent[i].rank = 0;
    }

    int s,d,sp,dp;
    bool cycle = false;
    bool visited[V];
    memset(visited , false , sizeof(visited));

    for(int i = 0; i < edges.size(); i++) {
        s = edges[i].first;
        d = edges[i].second;

        sp = find_parent(parent , s);
        dp = find_parent(parent , d);

        if(sp == dp)
            cycle = true;
        else {
            make_union(parent[sp] , parent[dp]);
        }
    }

    for(int i = 0; i < V; i++)
        cout << "vertex : " << i << " parent : " << parent[i].s << " rank : " << parent[i].rank << endl;

}
int GRAPH::find_parent(PARENT_RANK *parent , int s) {
    if(parent[s].s == s)
        return s;
    return find_parent(parent , parent[s].s);
}
void GRAPH::make_union(PARENT_RANK &p1 , PARENT_RANK &p2) {
    if(p1.rank > p2.rank)
        p2.s = p1.s;
    else if(p1.rank < p2.rank)
        p1.s = p2.s;
    else {
        p2.s = p1.s;
        p1.rank += 1;
    }
}
int main()
{
    GRAPH g(6);
    g.insert_edge(0 , 1);
    g.insert_edge(0 , 2);
    g.insert_edge(0 , 3);
    g.insert_edge(1 , 2);
    g.insert_edge(1 , 3);
    g.insert_edge(2 , 3);
    g.insert_edge(4 , 5);
    g.union_find();
return 0;
}
