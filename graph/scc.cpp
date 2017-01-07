#include <bits/stdc++.h>
using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define PB push_back
#define FOR(i , n) for(i = 0; i < n; i++)

vector <vector<int> >g;
vector <vector<int> >g1;

bool state[1000];
int c;


typedef struct vartex {
	int ind;
	int start;
	int ed;
}vartex;

vector <vartex>var;
bool compare(vartex a1 , vartex a2) {
	if (a1.ed < a2.ed)
	return false;

	return true;
}
void mark(int s) {
    state[s] = true;
    var[s].ind = s;
    var[s].start = c++;
    tr(g[s] , it) {
        if(!state[*it])
        mark(*it);
	 
    }
    var[s].ed = c;
	c++;
}

void dfs(int s)
{
	state[s] = true;
	printf("%d", s);
	tr(g1[s] , it) {	
		if(!state[*it])
		dfs(*it);
		
	}
}
int main()
{
    int i;
    int v;
    scanf("%d", &v);
  
    g.resize(v+1);
    g1.resize(v+1);
    var.resize(v+1);  
    int s, d;
    while(1) {
        scanf("%d%d", &s, &d);
        if(s == -1)
        break;
       
        g[s].PB(d);
        g1[d].PB(s);
       
    }
    memset(state , false , sizeof(state));
    FOR(i , v){
        c = 1;
        if(!state[i+1])
        mark(i+1);
    }

    sort(var.begin()+1 , var.end() , compare);
	
	//FOR(i , v)
	//cout<<var[i+1].ind<<" "<<"s "<<var[i+1].start<<" end "<<var[i+1].ed<<endl;
   memset(state , false , sizeof(state));
   FOR(i , v) {
	if(!state[i+1]){
	dfs(var[i+1].ind);
	cout<<"\n";
	}
    }	
		
return 0;
}
