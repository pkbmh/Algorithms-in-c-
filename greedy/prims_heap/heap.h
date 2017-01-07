#ifndef HEAP_H  
#define HEAP_H
#include <bits/stdc++.h>
using namespace std;
typedef pair <int , int > pp;

void build_min_heap(int a[][2], int n, int index[]) ;
void minheapify(int arr[][2], int i, int n, int index[]) ;
void decrease_key(int arr[][2], int i, int k, int index[]) ;
pp extract_min (int arr[][2] , int &n , int index[]);

#endif
