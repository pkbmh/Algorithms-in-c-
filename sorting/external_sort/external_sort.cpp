// Author :Sumit Sethia
// Program to Implement external sort
// It creates 10 files containing random numbers (even number of numbers in each file is random , Just for fun !!)
// sort each file
// Merge the files into a single file with the help of Min heap . 

#include<stdio.h>
#include<iostream>
#include <cstdlib>
#include<string.h>
#include<algorithm>
#include<vector>
#include "heap.h"

using namespace std;

vector <int >buff;

int main() {
//Ten file pointers
FILE *fp[10];

char d[5] = ".txt";
char c[15];

//Open files for writing (file name "i.txt" , i >= 0 && i < 10)

for (int i = 0; i < 10; i++) {
char dig = (char)(((int)'0')+i);
c[0] = dig;
c[1] = '\0';
strcat(c , d);
fp[i] = fopen(c , "w+");
}

long long t = 1000;

srand(time(NULL));

// Generate random numbers and insert into a random file 

while (t--) {
int x = rand() % 10000;
int z = rand() % 10;
fprintf(fp[z] , "%d\n", x);
}

int x , max = 10000;

// a[11][2] -> Heap array having element and file pointer index 

int a[11][2];   	//a[][1] contains index(to which file the element belongs) and a[][0] contains the element .
int check;
for (int i = 0; i < 10; i++) {
	int index = 0;
	rewind(fp[i]);
	buff.clear();
// Copy each file's data into an array
	while (!feof(fp[i])) {
		fscanf(fp[i] , "%d" , &x);
		buff.push_back(x);
	index++;
	}

//Sort the array 
	sort(buff.begin() , buff.end());

	c[0] = (char)(((int)'0')+i);

	rewind(fp[i]);
//Copy the sorted array back to file 
	for (int z = 0; z < index; z++) 
	fprintf(fp[i] , "%d\n", buff[z]);

//Insert max at the end of each file 	
	fprintf(fp[i] , "%d\n", max);
	fscanf(fp[i] , "%d", &check);
	printf("%d\n", check);
}

//Merge the sorted files

//First Create a heap array by taking 1st element of each file into the array and also maintaing the index of file pointer i.e to which file that number belongs .

for (int i = 0; i < 10; i++) {
rewind(fp[i]);
fscanf(fp[i] , "%d", &a[i+1][0]);
a[i+1][1] = i;
}

//Build Min Heap

build_min_heap(a , 10);

FILE *output;

output = fopen("out.txt", "w+");

while(a[1][0] != max) {

	fprintf(output , "%d\n", a[1][0]);
	fscanf(fp[a[1][1]] , "%d", &a[1][0]);
	minheapify(a , 1 , 10);

}

for (int i = 0; i <= 9; i++)
fclose(fp[i]);
fclose(output);

return 0;
}

