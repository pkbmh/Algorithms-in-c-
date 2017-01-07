#include <bits/stdc++.h>
using namespace std;
#define PII pair <int , int>
#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

template<class x>void swaper(x &a , x &b) { x t = a; a = b; b = t; }
typedef struct HEAP_NODE{
    int ver;
    int dist;
    int parent;
    HEAP_NODE(){}
    HEAP_NODE(int v , int p , int d) { ver = v ; parent = p; dist = d;}
}HEAP_NODE;

class MIN_HEAP {
public:
    int capacity;
    int filled;
    HEAP_NODE *arr;
//public:
    MIN_HEAP(int c) {
        capacity = c;
        filled = 0;
        arr = new HEAP_NODE[c];
    }
    void insert_node(int , int , int );
    void build_heap(int );
    void heapify();
    void update(int , int , int);
    HEAP_NODE extract_min();
};
void MIN_HEAP::build_heap(int i) {
    int t = i;
    int next = i * 2;
    if(next+1 < filled && arr[t].dist > arr[next+1].dist)
        t = next+1;
    if(next+2 < filled && arr[t].dist > arr[next+2].dist)
        t = next+2;

    if(t != i) {
        swaper(arr[i] , arr[t]);
        build_heap(t);
    }
}
void MIN_HEAP::heapify() {
    int i = filled / 2;
    for(; i >= 0; i--)
        build_heap(i);
}
void MIN_HEAP::insert_node(int ver , int parent  , int d) {
    arr[filled] = HEAP_NODE(ver , parent , d);
    filled++;
    //heapify();
}
HEAP_NODE MIN_HEAP::extract_min() {
    HEAP_NODE root = arr[0];
    filled--;
    if(filled > 0) {
        arr[0] = arr[filled];
        build_heap(0);
    }
    return root;
}
void MIN_HEAP::update(int v , int p , int d) {
    int i;

    for(i = 0; i < filled; i++){
        if(v == arr[i].ver)
            break;
    }

    if(arr[i].dist > d){
        arr[i].dist = d;
        arr[i].parent = p;
    }
    heapify();
}
class GRAPH {
    int v;
    list< PII >*vertex;
public:
    GRAPH(int a) {
        v = a;
        vertex = new list<PII>[a];
    }
    void insert_edge(int s,  int d , int w) { vertex[s].push_back(make_pair(d ,w)); }
    int prims_mst();
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
int GRAPH::prims_mst()
{
    int mst_weight = 0;
    MIN_HEAP mst_heap(v);
    bool visited[v];
    memset(visited , false , sizeof(visited));
    int s = 0; // starting from 0;
    for(int i = 0; i < v; i++)
        mst_heap.insert_node(i , -1 , INT_MAX);
    mst_heap.update(0 , -1 , 0);
    while(mst_heap.filled > 0) {
        HEAP_NODE tmp = mst_heap.extract_min();
        s = tmp.ver;
        visited[s] = true;
        cout << tmp.parent << " -> " << tmp.ver << " :: " << tmp.dist << endl;
        mst_weight += tmp.dist;
        tr(vertex[s] , it) {
            if(!visited[it->first])
                mst_heap.update(it->first , s , it->second);
        }
    }
    //cout << " ttmtmt " << mst_heap.arr[8].dist << endl;
    return mst_weight;
return 0;
}

int main()
{
    GRAPH graph(9);
    FILE *fp = fopen("input_prims_mst.txt" , "r");
    int s,d,w;
    while((fscanf(fp , "%d %d %d" , &s , &d , &w)) != EOF){
        graph.insert_edge(s , d , w);
        graph.insert_edge(d , s , w);
    }

   // graph.print();
    int mst = graph.prims_mst();

   cout << "Weight of MST is " << mst << endl;

return 0;
}
