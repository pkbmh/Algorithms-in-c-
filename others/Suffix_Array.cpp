#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
 
char a[1001];
int len;
int gap;
vector <int >suf;
vector <int > pos;
vector <int > tmp;
vector <int >lcp;
 
bool comp(int i, int j)
{
  if (pos[i] != pos[j])
    return pos[i] < pos[j];
  i += gap;
  j += gap;
  return (i < len && j < len) ? pos[i] < pos[j] : i > j;
}
 
int main() {
 
int t;
scanf("%d", &t);
 
while (t--) {
scanf("%s", a);
suf.clear();
tmp.clear();
pos.clear();
lcp.clear();
 
for (len = 0; a[len] != '\0'; len++);
 
suf.resize(len);
tmp.resize(len);
pos.resize(len);
lcp.resize(len);
 
for (int i = 0; i < len ; i++) {
    suf[i] = i;
    pos[i] = (int)a[i] - 'A';
}
 
for (gap = 1; ; gap = gap*2) {
sort(suf.begin() , suf.begin() + len , comp);
 
for (int i = 0; i < len - 1 ; i++)
    tmp[i+1] = tmp[i] + comp(suf[i], suf[i+1]);
 
for (int i = 0; i < len; i++)
    pos[suf[i]] = tmp[i];
if (tmp[len-1] == len - 1)
break;
}
 
int sum = 0;
for (int i = 0; i < len - 1 ; i++) {
 
for (int j = 0; j + max(suf[i], suf[i+1]) < len; j++) {
if (a[j+suf[i]] == a[j+suf[i+1]]){
lcp[i+1]++;
sum++;
}
else
break;
}
}
 
for (int i = 0; i < len; i++) 
sum = sum + suf[i];
 
 
 
printf("%d\n", len*len - sum);
}
return 0;
} 
