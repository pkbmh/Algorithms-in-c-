#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	FILE *fp;
	//srand (10000000);
	fp = fopen("input.dat", "w");
	fprintf(fp , "%d\n", n);
	double ran1 ,ran2;
	for(int i = 0; i <= n; i++) {
		ran1 = rand() % 1000;
		ran2 = rand() % 1000;
		ran1 = ran1 / 3.0;
		ran2 = ran2 / 3.0;
		fprintf(fp , "%lf ", ran1);
		fprintf(fp , "%lf\n", ran2);
	}
return 0;
}
	
		
