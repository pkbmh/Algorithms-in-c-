#include <bits/stdc++.h>
using namespace std;

bool check_circular(char *moves , int len) {
    int i,j;
    i = j = 0;
    int face = 0;
    for(int k = 0; k < len; k++) {
       if(moves[k] == 'R')
            face = (face+1)%4;
       else if(moves[k] == 'L')
            face = (face+3)%4;
       else {
            if(face == 0)
                i--;
            else if(face == 1)
                j++;
            else if(face == 2)
                i++;
            else
                j--;
       }
    }
    return (i == 0 && j == 0);
}
int main()
{
    char *moves = "GLGLGLG";
    int len = strlen(moves);

    bool res = check_circular(moves , len);
    if(res)
        cout << " yes " << endl;
    else
        cout << "NO" << endl;
return 0;
}
