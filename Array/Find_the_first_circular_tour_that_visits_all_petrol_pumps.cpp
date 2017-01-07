#include <bits/stdc++.h>
using namespace std;

typedef struct station {
    int patrol;
    int distance;
}station;

int find_start_point(station point[] , int n) {
    int start = 0;
    int end = 1;
    int cur_patrol = point[0].patrol - point[0].distance;

    while(start != end || cur_patrol < 0) {
        while(start != end && cur_patrol < 0) {
            cur_patrol -= point[start].patrol - point[start].distance;
            start = (start+1)%n;
            if(start == 0)
                return -1;
        }
        cur_patrol += point[end].patrol - point[end].distance;
        end = (end+1)%n;
    }

    return start;
}
int main()
{
    cout << "Number of total station " << endl;
    int n;
    cin >> n;

    station point[n];

    for(int i = 0; i < n; i++)
        cin >> point[i].patrol >> point[i].distance;

    int spoint = find_start_point(point , n);
    cout << "Start from :: " << spoint << endl;

return 0;
}
