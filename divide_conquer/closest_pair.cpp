#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef struct point{
    int x;
    int y;
    //point(){};
    point(int a , int b) {
    x = a;
    y = b;
    }
}point;

vector<point>input_pair;
vector<point>midstrip;
int n;
bool compairx(point a , point b) {
    if(a.x > b.x)
    return false;
    else return true;
}

bool compairy(point a, point b) {
    if(a.y > b.y)
    return false;
    else return true;
}

double get_distance(point a , point b) {
    double d = sqrt(pow(a.x-b.x , 2) + pow(a.y-b.y , 2));
return d;
}
double minimum(double a , double b) {return ((a > b) ? b : a);}

double find_instrip(double dd) {
    int size = midstrip.size();
    sort(midstrip.begin() , midstrip.end() , compairy);
    double min = dd;

      for (int i = 0; i < size; ++i){
               for (int j = i+1; j < size && (midstrip[j].y - midstrip[i].y) < min; ++j) {
                if (get_distance(midstrip[i],midstrip[j]) < min)
                    min = get_distance(midstrip[i], midstrip[j]);
        }
    }
 
    return min;
}
double finddistance(int l , int r) {
    if(r - l < 2)
    return INT_MAX;
   
    int mid = (l + r) / 2;

    int midx = input_pair[mid].x;
    int midy = input_pair[mid].y;

    double dd,dc,dl,dr,dm;

    dl = finddistance(l , mid);
    dr = finddistance(mid+1 , r);

    dd = minimum(dl , dr);
    midstrip.clear();
    for(int i = 0; i < n; i++) {
         if (abs(input_pair[i].x - midx) < dd)
        midstrip.push_back(input_pair[i]);
         }
    dm = find_instrip(dd);
    double ans = minimum(dm , dd);
return ans;
}
int main()
{
    int i, j,x,y;
    scanf("%d", &n);

    input_pair.clear();
    input_pair.resize(n);

    for(i = 0; i < n; i++){
        scanf("%d%d",&x,&y);
        input_pair[i].x = x;
        input_pair[i].y = y;
    }
    sort(input_pair.begin() , input_pair.end(),  compairx);
    /*for(i = 0; i < n; i++)
    printf("%d %d\n", input_pair[i].x , input_pair[i].y);*/
   
    double d = finddistance(0 , n-1);
    printf("%lf\n", d);
return 0;
}
