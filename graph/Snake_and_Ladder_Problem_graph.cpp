#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>

int minimum_step(int *moves , int n) {
    queue< PII >qu;
    qu.push(make_pair(0,0));
    bool visited[n];
    memset(visited , false , sizeof(visited));
    PII p1;
    while(!qu.empty()){
        p1 = qu.front();
         qu.pop();
        if(p1.first == n-1)
            break;
        for(int i = p1.first+1; i <= (p1.first+6) && i < n; i++) {
            if(!visited[i]) {
               PII p2;
                p2.second = p1.second+1;
                if(moves[i] != -1)
                    p2.first = moves[i];
                else
                    p2.first = i;

                qu.push(p2);
            }
        }
    }
    return p1.second;
}
int main()
{
    int n = 30;
    int moves[n];
    for(int i = 0; i < n; i++)
        moves[i] = -1;

    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    int min_step = minimum_step(moves , n);
    cout << "Minimum step to reach end " << min_step << endl;

return 0;
}
