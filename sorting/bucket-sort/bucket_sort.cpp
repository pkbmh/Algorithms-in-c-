#include <bits/stdc++.h>
using namespace std;
#define FOR(i , n) for(i = 0; i < n; i++)
#define tr(it , c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define PB push_back
#define max_val 100000
#define bucket_size 10
/*typedef struct node {
	int value;
	struct node *next;
}node;
*/

vector<float>tmp;
void swap1(float *a , float *b) {
	float t = *a;
	*a = *b;
	*b = t;
}
int partition (int l, int h)
{
	int x = tmp[h]; // pivot
	int i = (l - 1); // Index of smaller element
	for (int j = l; j <= h- 1; j++)
	{
	if (tmp[j] <= x)
	{
	i++; // increment index of smaller element
	swap1(&tmp[i], &tmp[j]); // Swap current element with index
	}
}
swap1(&tmp[i+1], &tmp[h]);
return (i + 1);
}
void quickSort(int l, int h)
{
	if(l >= h)
	return; 
	int p = partition(l, h); 
	quickSort(l, p - 1);
	quickSort(p + 1, h);
	 
	
}
int main(){
	
	int i;
	float t;
	unsigned long long int n;
	int index;
	scanf("%lld", &n);
	
	FILE *INPUT = fopen("input.txt" , "w");

	FOR(i , n) {
	//t = ((float)rand()/(float)(RAND_MAX));
	t = rand() % max_val;	
	fprintf(INPUT , "%f\n" , t);
	}

	fclose(INPUT);


	INPUT = fopen("input.txt" , "r");
 
	
	FILE *bucketfile[10];

	char filename[100];
	FOR(i , 10) {
		snprintf(filename , sizeof filename , "%d.txt", i);
		bucketfile[i] = fopen(filename , "w");
	}
	
	
	FOR(i , n) {
			
		fscanf(INPUT , "%f" , &t);
		 index = t / (max_val / bucket_size);
		fprintf(bucketfile[index] ,"%f\n", t );
	} 


	FOR(i , 10) { 
		 fclose(bucketfile[i]);
	}
	FILE *OUT = fopen("output.txt", "w");
	
	FOR(i , 10) {
		tmp.clear();
		snprintf(filename , sizeof filename , "%d.txt", i);
		bucketfile[i] = fopen(filename , "r");	
			while(fscanf(bucketfile[i] , "%f" , &t) != EOF)
					tmp.PB(t);
		
			int size = tmp.size();
			
			//quickSort(0 , size-1);
			sort(tmp.begin() , tmp.end());
			fclose(bucketfile[i]);
			
			//snprintf(filename , sizeof filename , "output%d.txt", i);
		      //  bucketfile[i] = fopen(filename , "w");	
			
			int k = 0;
			
			FOR(k , size){
				//fprintf(bucketfile[i] , "%f\n" , tmp[k]);
				fprintf(OUT , "%f\n" , tmp[k]);
			}
			//fclose(bucketfile[i]);
		}
		fclose(OUT);
return 0;
}
			 
 	
	
	
