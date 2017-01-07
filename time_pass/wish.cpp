#include<iostream>
using namespace std;
int main()
{
int i,j,k;
cout<<"\n";
cout<<"\n";
cout<<"\n";
for(i=1;i<=3;i++)
{
cout<<"\n\t\t";
for(j=1;j<=3-i;j++)
{
cout<<" ";
}
k=0;
while(k!=2*i-1)
{
cout<<"*";
k++;
}
}
for(i=3;i>=1;i--)
{
cout<<"\n\t\t";
for(j=3-i;j>=1;j--)
{
cout<<" ";
}
k=0;
while(k!=2*i-1)
{
cout<<"*";
k++;
}
}
for(i=9;i>=6;i--)
{
cout<<"\n\t ";
for(j=9-i;j>=1;j--)
{
cout<<" ";
}
k=0;
while(k!=2*i-1)
{
cout<<"*";
k++;
}
}
cout<<"\n";
cout<<"\n";
for(i=0;i<2;i++)
{
cout<<"\n\t";
for(j=0;j<2;j++)
{
cout<<"*";
}
cout<<" ";
for(j=0;j<2;j++)
{
cout<<"*";
}
}
for(i=0;i<2;i++)
{
cout<<"\n\t";
for(j=0;j<7;j++)
{
cout<<"*";
}
}
for(i=0;i<2;i++)
{
cout<<"\n\t";
for(j=0;j<2;j++)
{
cout<<"*";
}
cout<<" ";
for(j=0;j<2;j++)
{
cout<<"*";
}
}
cout<<" APPY\n";
for(i=0;i<1;i++)
{
cout<<"\n\t\t\t";
for(j=0;j<7;j++)
{
cout<<"*";
}
}
for(i=0;i<4;i++)
{
cout<<"\n \t\t\t";
cout<<" ";
for(j=0;j<2;j++)
{
cout<<"*";
}
cout<<" ";
for(j=0;j<2;j++)
{
cout<<"*";
}
}
cout<<" IWALI.....";
for(i=0;i<1;i++)
{
cout<<"\n\t\t\t";
for(j=0;j<7;j++)
{
cout<<"*";
}
}
cout<<"\n\t\t\t\t.........From Pankaj Birat ..............";
cout<<"\n";
return 0;
}
