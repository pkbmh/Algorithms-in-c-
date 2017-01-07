#include <bits/stdc++.h>
using namespace std;

vector<int>f1,f2,t1,t2;

typedef struct station_information {
	int f1,f2,t1,t2;
}si;
vector<si>station_info;

vector<vector <int> >dp;

int enter1,enter2,exit1,exit2;
int ALS(int l , int h , int s) {
	int cost1, cost2;
	if(l == h) { 
		if(s == 1)
			dp[s][l] = exit1;
		else dp[s][l] = exit2;
	
	return dp[s][l];
			
	}
	
	if(dp[s][l] != 0)
		return dp[s][l];
	
	
	if(s == 0) {
		cost1 = station_info[l+1].f1+enter1 + ALS(l+1 , h , 1);
		cost2 = station_info[l+1].f2+enter2 + ALS(l+1 , h , 2);
	}
	else if(s == 1) {
		cost1 = station_info[l+1].f1 + ALS(l+1 , h , 1);
		cost2 = (station_info[l+1].f2 + station_info[l+1].t1)+ ALS(l+1 , h , 2);
	}
	else {
		cost1 = station_info[l+1].f2 + ALS(l+1 , h , 2);
		cost2 = (station_info[l+1].f1 + station_info[l+1].t2)+ ALS(l+1 , h , 1);
	}
	
	dp[s][l] = min(cost1 , cost2);
	
	return dp[s][l];
}
int main()
{
	int n,t1,t2,f1,f2;
	scanf("%d", &n);
	station_info.clear();
	station_info.resize(n+1);
	int d = 3;
	dp.clear();
	dp.resize(d);
	dp[1].resize(n+1);
	dp[2].resize(n+1);
	dp[0].resize(n+1);
		
	printf("Enter station information on line 1 and 2\n");
		scanf("%d%d", &f1 , &f2);
		station_info[1].f1 = f1;
		station_info[1].t1 = 0;
		station_info[1].f2 = f2;
		station_info[1].t2 = 0;
	for(int i = 2; i <= n; i++) {
		scanf("%d%d%d%d", &f1,&t1,&f2,&t2);
		station_info[i].f1 = f1;
		station_info[i].t1 = t1;
		station_info[i].f2 = f2;
		station_info[i].t2 = t2;
	}
	printf("Enter entry and exiting time from 1 and 2\n");
	scanf("%d%d" , &enter1,&enter2);
	scanf("%d%d", &exit1 , &exit2);
	int ans = ALS(0 , n , 0);
	printf("Minimum cost is = %d\n", ans);
return 0;
}
