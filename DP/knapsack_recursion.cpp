#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> v;
vector<int>w;
int n;
int  max(int a , int b) {
return (a>b) ? a : b;
}
int  ks(int c, int i){
if(i > n-1)
return 0;
if(w[i] > c)
return ks(c, i+1);
else 
return max(ks(c, i+1), (v[i] + ks(c-w[i] , i+1)));

}
int main(){
scanf("%d", &n);
v.resize(n);
w.resize(n);
for(int i = 0; i < n; i++){
scanf("%d%d", &v[i],&w[i]);
}
int c;
scanf("%d", &c);
printf(" maximam benefit is = %d\n", ks(c, 0));
scanf("%d", &n);
}
