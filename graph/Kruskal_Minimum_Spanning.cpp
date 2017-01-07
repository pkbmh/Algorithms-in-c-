#include <bits/stdc++.h>
using namespace std;

typedef struct PARENT {
    int p;
    int rank;
}PARENT;

typedef struct EDGE {
    int s , d , w;
    EDGE(int a , int b , int c) {s = a; d = b; w = c;}
}EDGE;
bool comp(EDGE p1 , EDGE p2) {
    return (p1.w < p2.w);
}
class GRAPH {
    int v;
    vector < EDGE > edges;
public:
    GRAPH(int a) {v = a;}
    void insert_edge(int s , int d , int w) {edges.push_back(EDGE(s , d ,w));}
    int find_parent(PARENT * , int );
    int kruskal_mst();
    void make_union(PARENT &p1 , PARENT &p2);
};

int GRAPH::find_parent(PARENT *parent , int s) {
    if(s == parent[s].p)
        return s;
    else
        return find_parent(parent , parent[s].p);
}

void GRAPH::make_union(PARENT &p1 , PARENT &p2) {
    if(p1.rank > p2.rank)
        p2.p = p1.p;
    else if(p2.rank > p1.rank)
        p1.p = p2.p;
    else {
        p2.p = p1.p;
        p1.rank += 1;
    }
}

int GRAPH::kruskal_mst() {
    sort(edges.begin() , edges.end() , comp);
    PARENT parent[v];
    for(int i = 0; i < v; i++) {
        parent[i].p = i;
        parent[i].rank = 0;
    }
    int mst_weight = 0;
    int picked = 0;

    int i = 0;
    int s,d,sp,dp,w;
    while(picked < v-1) {
        EDGE tmp = edges[i];
        s = tmp.s;
        d = tmp.d;
        w = tmp.w;

        sp = find_parent(parent , s);
        dp = find_parent(parent , d);

        if(sp != dp) {
            make_union(parent[sp] , parent[dp]);
            mst_weight += w;
            picked++;
        }
        i++;
    }
    for(int i = 0; i < v; i++)
        cout << parent[i].p << " -> " << i << endl;

    return mst_weight;
}

int main()
{
    GRAPH graph(9);
    FILE *fp = fopen("input_prims_mst.txt" , "r");
    int s,d,w;
    while((fscanf(fp , "%d %d %d" , &s , &d , &w)) != EOF){
        graph.insert_edge(s , d , w);
        //graph.insert_edge(d , s , w);
    }

   // graph.print();
    int mst = graph.kruskal_mst();

   cout << "Weight of MST is " << mst << endl;

return 0;
}
