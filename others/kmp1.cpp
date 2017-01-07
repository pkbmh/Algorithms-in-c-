#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector <int> k;
void create_array(char a[] , int len)
{
k[0] = 0;
 int j = 0;
 int i; 
 for(i = 1;i < len; i++) {
 while(j > 0 && a[j] != a[i])
 j = k[j-1];
 
 if(a[j] == a[i])
 j++;
  
 k[i] = j;
 }
 }
int kmp(char a[] , char p[]) {
int la = strlen(a);
int lp = strlen(p);
create_array(a , la);
int i = 0;
int j = 0;
while(i < la) {
if(j == -1) {
i++;
j = 0;
}
else if(a[i] == p[j]){
i++;
j++;
if(j == lp)
return i;
}
else
j = k[j];
}
return -1;
}

int main()
{
int i;
cout<<"Enter text string"<<endl;
char a[1000];
char p[1000];
cin>>a;
cout<<"Enter text to be search"<<endl;
cin>>p;
int len = strlen(a);
k.resize(len);
for(i = 0; i < len; i++)
k[i] = 0;

cout<<"text found at position = "<<kmp(a,p)<<endl;
for(i = 0; i < len; i++)
cout<<k[i]<<" ";
return 0;
}
