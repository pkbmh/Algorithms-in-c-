#include <bits/stdc++.h>
using namespace std;

int minimum_step(int *moves , int n) {
    int step[n+1];
    for(int i = 0; i <= n; i++)
        step[i] = i;

    step[0] = 0;
    for(int i = 0; i <= n-6; i++) {
        for(int j = 1; j <= 6; j++) {
            if(moves[i] > i)
                step[moves[i]] = min(step[i], step[moves[i]]);

            step[i+j] = min(step[i]+1 , step[i+j]);
        }
    }

    return step[n-1];
}
int main()
{
    int n = 30;
    int moves[n];
    for(int i = 0; i < n; i++)
        moves[i] = 0;

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
