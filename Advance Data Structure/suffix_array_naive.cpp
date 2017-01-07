#include <bits/stdc++.h>
using namespace std;

typedef struct suffix{
    int index;
    char *suff;
} suffix;

bool compare(suffix s1 , suffix s2) {
    return (strcmp(s1.suff , s2.suff) < 0 ? 1 : 0);
}
int *build_suffix_array(char *str , int len) {
    suffix suffixs[len];

    for(int i = 0; i < len; i++) {
        suffixs[i].index = i;
        suffixs[i].suff = (str+i);
    }
    sort(suffixs , suffixs+len , compare);
    int *suffix_array = new int[len];

    for(int i = 0; i < len; i++)
        suffix_array[i] = suffixs[i].index;

    return suffix_array;
}
int main()
{
        char str[] = "banana";
        int len = strlen(str);

        int *suffix_array = build_suffix_array(str , len);
        for(int i = 0; i < len; i++)
            cout << suffix_array[i] << " ";
        cout << endl;

return 0;
}
