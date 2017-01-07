/*Rabin-Karp Algorithm*/

#include <bits/stdc++.h>
using namespace std;
#define d 256
#define prime 1000000007

int Search_patterns(char *text , char *pat) {
    unsigned int tlen = strlen(text);
    unsigned int plen = strlen(pat);

    unsigned int h = 1;
    unsigned int hash_text = 0;
    unsigned int hash_pat = 0;

    for(int i = 0; i < plen-1; i++)
        h = (h * d)%prime;

    for(int i = 0 ; i < plen; i++) {
        hash_pat = (hash_pat * d + pat[i])%prime;
        hash_text = (hash_text * d + text[i])%prime;
    }
    for(int i = 0 ; i <= (tlen-plen); i++) {
        if(hash_pat == hash_text) {
            int j;
            for(j = 0; j < plen; j++) {
                if(text[i+j] != pat[j])
                    break;
            }
            if(j == plen)
                cout << "Patterns found at index :: " << i << endl;
        }

        if(i < tlen-plen) {
            hash_text = (d*(hash_text - text[i]*h) + text[i+plen])%prime;
            if(hash_text < 0)
                hash_text += prime;
        }
    }
    return -1;
}
int main()
{
    char *text = "AABAACAADAABAAABAA";
    char *pat = "AAD";

    Search_patterns(text , pat);

return 0;
}
