#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
vector <int> a;
void swap(int *a , int *b){
    int x;
    x = *a;
    *a = *b;
    *b = x;
}
int part(int s , int e)
{
    int i;
    int p = s-1;
    int x = a[e-1];
   
    for(i = s; i < e-1; i++) {
        if(a[i] < x){
            p++;
            swap(&a[i], &a[p]);
        }
    }
    swap(&a[p+1], &a[e-1]);
   
    return p+1;
}
void selection_sort(int s, int e){
    int i,j;
    int min;
    for(i = s; i < e; i++){
        min = i;
        for(j = i+1; j < e; j++){
            if(a[j] < a[min])
            min = j;
        }
        swap(&a[min], &a[i]);
    }
}
void qsort(int s, int e , int ss)
{
    if(e-s <= ss){
        selection_sort(s , e);
    }
    else if(s < e){
        int pi = part(s , e);
        qsort(s, pi , ss);
        qsort(pi+1 ,e ,ss);
    }
}
int main(){
    int i;
    int n,ss;
// clock_t t = clock();
    cin>>n;
    cin>>ss;
    a.resize(n);
    for(i = 0; i < n; i++) {
    a[i] = rand();
    cout<<a[i]<<" ";
   }
   cout<<endl;
     clock_t t = clock();
      qsort(0,n,ss);
     clock_t t2 = clock();
//selection_sort(0,n);
   
        for(i = 0; i < n; i++)
        cout<<a[i]<<" ";
       
        cout<<endl;
        printf("Time taken: %.6fs\n", t2-t);
}
