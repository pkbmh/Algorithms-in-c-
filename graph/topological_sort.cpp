#include <bits/stdc++.h>
using namespace std;
#define tr(c ,it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define PB push_back
vector <vector <int> >g;
vector <int>ts;
stack<int>stack;
bool state[10000];
void topological_sort(int s) {
   
    state[s] = true;
    tr(g[s] , it) {
        if(!state[*it])
        topological_sort(*it);
    }
    ts.PB(s);
}
int main()
{
    int i;
    int v;
    scanf("%d", &v);
   
    g.resize(v+1);
    int s, d;
    while(1) {
        scanf("%d%d", &s, &d);
        if(s == -1)
        break;
        g[s].PB(d);
    }
    memset(state , false , sizeof(state));
    for(i = 0; i <= v; i++){
    if(!state[i])
    topological_sort(i);
    }
    tr(ts , it)
    cout<<*it<<endl;
return 0;
}
