#include  <bits/stdc++.h>
using namespace std;

int main()
{
    char str[] = "ge eks for geek";
    int c = 0;
    for(int i = 0; i < strlen(str); i++)
        if(str[i] != ' ')
            str[c++] = str[i];

    str[c] = '\0';
    cout << str << endl;
return 0;
}
