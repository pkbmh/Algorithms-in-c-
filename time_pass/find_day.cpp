#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
int leap[] = {31,29,31,30,31,30,31,31,30,31,30,31};
int aleap[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int i,j,t_day;
int sd,sm,sy,ed,em,ey;
string day[] = {"MONDAY","THUSDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
 sd = sm = 1;
 sy = 1900;
cout<<"Enter  DD/MM/YY"<<endl;
cin>>ed>>em>>ey;

if(ey < 1900 && ey > 1500)
sy = 1500;
else if(ey < 1500 && ey > 1100)
sy = 1100;
else if(ey < 1100 && ey > 700)
sy = 700;
else if(ey > 2300 && ey < 2700)
sy = 2300;
else if(ey > 2700 && ey < 3100)
sy = 2700;
else if(ey > 3100 && ey < 3500)
sy = 3100;

int leaps = 0;
int leape = 0;
 if(sy%400 ==0 || (sy%100 != 0 && sy%4 == 0))
leaps = 1;

if(ey%400 ==0 || (ey%100 != 0 && ey%4 == 0))
leape = 1;

int lds;
if(sy != ey) {
if(leaps == 1) {
lds = leap[sm-1] - sd;
for(i = sm; i <= 11; i++)
lds = lds + leap[i];
}
else {
lds = aleap[sm-1] - sd;

for(i = sm; i <= 11; i++)
lds = lds + aleap[i];
}
int lde;

if(leape == 1) {
lde = ed;
for(i = 0; i < em-1; i++)
lde = lde + leap[i];
}
else {
lde =  ed;

for(i = 0; i < em-1; i++)
lde = lde + aleap[i];
}

 t_day = lds + lde;
for(i = sy+1; i < ey; i++) {
if(i%400 ==0 || (i%100 != 0 && i%4 == 0))
t_day = t_day + 366;
else t_day = t_day + 365;
}
//cout<<"Days  between these two date = "<<t_day<<endl;
}
else if (sm != em){
if(leaps == 1) {
t_day = leap[sm-1] - sd + ed;
for(i = sm; i < em-1; i++)
t_day = t_day + leap[i];
}
else{
t_day = aleap[sm-1] - sd + ed;
for(i = sm; i < em-1; i++)
t_day = t_day + aleap[i];
}
//cout<<"Days  between these two date = "<<t_day<<endl;
}
else {
 t_day = ed-sd;

//cout<<"Days  between these two date = "<<t_day<<endl;
}
int d = t_day % 7;
cout<<day[d]<<endl;
return 0;
}

