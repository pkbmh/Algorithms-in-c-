#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int main()
{
int n;
long int x;
scanf("%d", &n);
set<long> s;
while(n--) {
long int p;
scanf("%ld", &p);
if(!(s.find(p) != s.end())) 
x = p;

s.insert(p);
}
printf("%ld\n", x);
return 0;
}
