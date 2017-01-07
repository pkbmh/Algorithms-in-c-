#include <bits/stdc++.h>
using namespace std;

vector<int>f1,f2,t1,t2;

typedef struct station_information {
	int f1,f2,t1,t2;
}si;
vector<si>station_info;

int main()
{
	int n,t1,t2,f1,f2, enter1,enter2,exit1,exit2;
	scanf("%d", &n);
	station_info.clear();
	station_info.resize(n+1);
	int cost1[n+1];
	int cost2[n+1];
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
	
	cost1[1] = enter1+station_info[1].f1;
	cost2[1] = enter2+station_info[1].f2; 
	
	for(int i = 2; i <= n; i++) {
		cost1[i] = min(cost1[i-1]+station_info[i].f1 , (cost2[i-1]+station_info[i].f1+station_info[i].t2));
		cost2[i] = min(cost2[i-1]+station_info[i].f2 , (cost1[i-1]+station_info[i].f2+station_info[i].t1));
		
	}
	int ans = min(cost1[n]+exit1 , cost2[n]+exit2);	   
	printf("Minimum cost is = %d\n", ans);
return 0;
}
