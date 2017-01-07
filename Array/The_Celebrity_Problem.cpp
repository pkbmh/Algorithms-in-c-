#include <bits/stdc++.h>
using namespace std;
#define N 4
bool matrix[N][N] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};

int find_celebrity()
{
    stack<int>st;
    int a,b;
    for(int i = 0; i< N; i++)
        st.push(i);

    while(st.size() > 1) {
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();

        if(matrix[a][b] == 1)
            st.push(b);
        else if(matrix[b][a] == 1)
            st.push(a);
    }
    return st.top();
}
int main()
{
    int celebrity = find_celebrity();
    cout << "celebrity is " << celebrity << endl;

return 0;
}
