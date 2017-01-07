#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> >t;
vector<int> color(0 , 0);
vector<int> d(0,0);
vector<int> node;

void DFS(int start ,int h) {
d[start] = h;
node[h] = start;
color[start] = 1;
//cout << start << endl;
for (int j = 0; j < t[start].size(); j++) {
if (color[t[start][j]] == 0) {
DFS(t[start][j], h+1);
}
}
}

int main() {
int n,j,i;
cin >> n;
t.resize(n+1);
color.resize(n+1);
d.resize(n+1);
node.resize(n+1);
//cout <<d[3]<<endl;

for (i = 0; i < n-1; i++) {
int a , b;
cin >> a >> b;
t[a].push_back(b);
t[b].push_back(a);
}

/*for ( i = 1; i <= n; i++) {
for (j = 0; j < t[i].size(); j++)
cout << t[i][j] << " ";
cout <<"\n";
}*/
DFS(1 , 0);
int max = 0;
for (i = 1; i <= n; i++) {
if (d[i] > max)
max = d[i];
}
for (i = 0; i <= n; i++) {
color[i] = 0;
d[i] = 0;
}
//cout << node[max] << endl;
DFS(node[max],0);

max = 0;
for (i = 1; i <= n; i++) {
if (d[i] > max)
max = d[i];
}

cout <<max<<endl;
return 0;
}

