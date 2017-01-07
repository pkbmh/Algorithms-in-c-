#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

typedef struct PAIR {
    int a;
    int b;
}PAIR;

bool comp(PAIR p1 , PAIR p2) { return (p1.a < p2.a); }

int maximum_chain_length(PAIR pairs[] , int n) {
    int *lis = new int[n];
    for(int i = 0; i < n; i++)
        lis[i] = 1;

    sort(pairs , pairs+n , comp);

    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(pairs[i].a > pairs[j].b && lis[i] < lis[j]+1)
                lis[i] = lis[j]+1;

    int max_len = INT_MIN;
    for(int i = 0; i < n; i++)
        max_len = max(max_len , lis[i]);

    delete [] lis;
    return max_len;
}
int main()
{
    PAIR pairs[] =  {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n = ARRAY_SIZE(pairs);

    int chain_len  = maximum_chain_length(pairs , n);
    cout << "Maximum chain length is " << chain_len << endl;

return 0;
}
