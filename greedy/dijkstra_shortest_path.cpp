#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define tr( c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef struct vartex {
    int v;
    int d;
    int p;
    bool state;
}vartex;

typedef pair<int , int> pii;
typedef vector< pii > vpii;
int v;
vector< vpii > graph;
vector< vartex > vartex_info;

struct comp {
    bool operator () ( const vartex a, const vartex b ) const {
        return a.d > b.d;
    }
}; 
void dijkstra(int s , int dist) {
    vartex start;
    start.p = -1;
    start.d = 0;
    start.state = false;
    start.v = s;
    
    priority_queue<vartex , vector< vartex > , comp>pq;
    pq.push(start);
    
    while(!(pq.empty())) {
        start = pq.top();
        pq.pop();
        int i = start.v;
        vartex_info[i].state = true;
        vartex_info[i].d = start.d;
        
        if(i == dist)
        break;
        
        tr(graph[i] , it) {
            int u = it->first;
            int w = it->second;
            if(!vartex_info[u].state && vartex_info[i].d + w < vartex_info[u].d) {
                vartex_info[u].d = vartex_info[i].d + w;
                vartex_info[u].p = i;
                
                pq.push(vartex_info[u]);
            }
        }
    }
            
        
        
}

int main() {
    int s,d,w;
    cin >> v;
    
    graph.resize(v);
    vartex_info.resize(v);
    
    while(1) {
        cin >> s >> d >> w;
        if(s == -1)
        break;
        graph[s].push_back(make_pair(d , w));
    }
    for(int i = 0; i < v; i++) {
        vartex_info[i].v = i;
        vartex_info[i].p = -1;
        vartex_info[i].d = INF;
        vartex_info[i].state = false;
    }
    cout<<"enter source and destination "<<endl;
    cin >> s >> d;
    dijkstra(s , d);
    
    int cv = d;
    while(cv != -1) {
        cout<<"vartex = "<< cv << " parent = "<<vartex_info[cv].p<<" d  = " <<vartex_info[cv].d <<endl;
        cv = vartex_info[cv].p;
    }
            
    return 0;
}
