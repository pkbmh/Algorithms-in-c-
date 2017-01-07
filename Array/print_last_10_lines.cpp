#include <bits/stdc++.h>
using namespace std;

void print_last_ten(char *str) {
    char *print_from;

    print_from = strrchr(str, '\n');

    int cnt = 1;
    while(print_from != NULL && cnt < 10) {
        print_from--;
        if(*print_from == '\n')
            cnt++;
    }
    cout << print_from << endl;
}
int main()
{
    char *str = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25";

    print_last_ten(str);

return 0;
}
