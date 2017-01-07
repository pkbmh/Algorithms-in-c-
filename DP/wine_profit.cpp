#include <iostream>
#include <cstdio>
using namespace std;
int p[10000];
int profit(int year , int lr , int rl) { 
if(lr > rl) return 0;
return max(profit(year+1, lr+1, rl) + (p[lr]*year) ,  profit(year+1 , lr , rl-1) + (p[rl] * year));
}
int main() {
int i,n;
cout<<"Enter how many wine you have"<<endl;
cin>>n;
cout<<"Enter price of each in sequence they are (-1 for end) "<<endl;
for(i = 0; i < n; i++)
cin>>p[i];
printf("maximum profit is = %d\n", profit(1,0 , n-1));
return 0;
}
