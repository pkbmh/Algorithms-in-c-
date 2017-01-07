#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int i;
int x = 0;
int j;
int p[600];
int lf[100000];
p[0] = 2;
int c = 1;
for(i = 3; i <= 651; i+=2) {
x  = 0;
for (j = 2; j <= sqrt(i); j++) {
if(i % j == 0) {
x++;
break;
}
}
if(x ==0)
p[c++] = i;
}
int b = 0;
for (i = 3; i <= 424243; i+=2){
x = 0;
for(j = 0; (j < c) && (j*p[j] <= i); j++) {
if(i % p[j] == 0 && i != p[j]){
x++;
break;
}
}
if(x == 0)
lf[b++] = i;
}
//for(i = 0; i < b; i++) {
cout<<c<<endl;
//}
return 0;
}
