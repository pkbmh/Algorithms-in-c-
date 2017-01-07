#include <stdio.h>
void hanoi(int n,char a,char b,char c) 
{
if(n == 1) {
printf("disk transform %c to %c", a, b);
printf("\n");
}
else {
hanoi(n-1, a,c,b);
hanoi(1,a,b,c);
hanoi(n-1, c,b,a);
}
}
int main()
{
int n;
char a,b,c;
a = 'A';
b = 'B';
c = 'C';
scanf("%d",&n);
hanoi(n,a,b,c);
return 0;
}
