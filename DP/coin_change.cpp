#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
int v[100];
int n;
int j = 0;
int coin[100];

int pc[100000];
int minimum(int a, int b) {
return (a>b) ? b : a;
}
int  findcoin(int p, int v) {
int c;
if(pc[p] != -1)
return pc[p];
if (p < v) 
return 0;
if(p == 0)
return 1;

c = findcoin(p-v , v)+1 ;
return c;
}
int main() {
int i;
int c;
int p;
int min;
scanf("%d", &p);
scanf("%d", &n);
for(i = 0; i < n ; i++) {
scanf("%d", &v[i]);
}
for(i = 0; i <= p; i++)
pc[i] = -1;

int tp;
for(i = 1; i <= p; i++) {
tp = i;
for(int j = n-1; j >= 0; j--) {
	coin[j] = -1;
	if(v[j] <= tp) {
	coin[j] = findcoin(tp-v[j] , v[j]);
}
}
min = 999999; 
for(int  k = 0; k < n; k++) {
	if (coin[k] >= 0)
	min = minimum(min,coin[k]);
}
pc[i] = min+1;
printf("p  %d = %d\n",i,pc[i] );
}

//printf("ans by loop = %d", coin1);
printf("ans by recursion = %d\n", pc[p]);
scanf("%d", &n);
return 0;
}
