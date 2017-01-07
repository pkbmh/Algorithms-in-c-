#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
vector<vector<int> > graph;
bool stated[1005];
bool stateb[1005];
queue<int>qb;
stack<int>qd;
int top1 = -1;
int sta[1005];
void push1(int a){
sta[++top1] = a;
}
void pop1(){
top1--;
}
int empty1() {
if(top1 == -1)
return 1;
else
return 0;
}
void sort()
{
int i;
int j;
int max = 0;
int tmp;
for(i = 0; i <= top1; i++)
{
max = i;
for(j = i+1; j <= top1; j++){
if(sta[j] > max)
max = j;
}
if(max != i) {
tmp = sta[max];
sta[max] = sta[i];
sta[i] = sta[max];
}
}
}


void  bfs(int s) {
memset(stateb , false , sizeof(stateb));
int v;
qb.push(s);
while(!(qb.empty())) {
v = qb.front();
printf("%d ", v);
qb.pop();
stateb[v] = true;
tr(graph[v] , it){
if(!stateb[*it]){
stateb[*it] = true;
qb.push(*it);
}
}
}
}
/*void dfs(int s) {
memset(stated , false , sizeof(stated));
int v;
qd.push(s);
while(!(qd.empty())) {
v = qd.top();
printf("%d ", v);
qd.pop();
stated[v] = true;
tr(graph[v] , it) {
if(!stated[*it]) {
stated[*it] = true;
qd.push(*it);
}
}
}
}*/
void dfs1(int s) {
printf("%d ", s);
stated[s] = true;
tr(graph[s] , it) {
if(!stated[*it])
dfs1(*it);
}
}
 
int main()
{
int  i,j;
int t;
int v;
int m;
int s,d;
int c = 0;
int st,n;
scanf("%d", &t);
while(t--) {
scanf("%d", &v);
graph.clear();
graph.resize(v+1);
//scanf("%d", &m);
for(i = 1; i <= v; i++) {
scanf("%d%d", &s, &m);
for(j = 1; j <= m;j++) {
scanf("%d",&d);
graph[s].push_back(d);
}
}
printf("graph %d\n", ++c);
while(1)
{
scanf("%d%d", &st,&n);
if(st == 0 && n == 0)
break;
if(n == 0){
memset(stated , false , sizeof(stated));
dfs1(st);
printf("\n");
continue ;
}
bfs(st);
printf("\n");

}

}
return 0;
}



