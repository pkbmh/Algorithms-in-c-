#include <iostream>
#include <cstdio>
using namespace std;
int p[10000];
int dp[1000][1000];
int profit(int year , int lr , int rl) { 
if(lr > rl) 
return 0;
if(dp[lr][rl] == -1)
dp[lr][rl] = max(profit(year+1, lr+1, rl) + (p[lr]*year) ,  profit(year+1 , lr , rl-1) + (p[rl] * year));

return dp[lr][rl];
}
int main() {
int j,i,n;
cout<<"Enter how many wine you have"<<endl;
cin>>n;
for(i = 0; i <= n; i++)
for(j = 0; j <= n; j++)
dp[i][j] = -1;
cout<<"Enter price of each in sequence they are (-1 for end) "<<endl;
for(i = 0; i < n; i++)
cin>>p[i];
printf("maximum profit is = %d\n", profit(1,0 , n-1));
return 0;
}
