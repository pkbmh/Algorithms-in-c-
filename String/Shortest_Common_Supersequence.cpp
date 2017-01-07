#include <bits/stdc++.h>
using namespace std;

void LCS(vector< vector < int > > &lcs , char *str1 , int len1 ,char *str2 , int len2) {
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(str1[i-1] == str2[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else
                lcs[i][j] = (lcs[i-1][j] >=  lcs[i][j-1]) ? lcs[i-1][j] : lcs[i][j-1];
        }
    }
}
void SCS(char *str1 , int len1 , char *str2 , int len2) {
    int i , j , l;
    vector < vector < int > > lcs(len1+1);
    for(i = 0; i <= len1; i++)
        lcs[i].resize(len2+1);

    LCS(lcs , str1 , len1 , str2 , len2);
    cout << "Length of LCS is " << lcs[len1][len2] << endl;

    int lcs_len = lcs[len1][len2];
    char str[lcs_len];
    str[lcs_len] = '\0';
    l = lcs_len-1;
    i = len1;
    j = len2;
   // cout << str << endl;
    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j-1]) {
            str[l] = str1[i-1];
            l--;
            i--;
            j--;
        }
        else if(lcs[i-1][j] >= lcs[i][j-1])
            i--;
        else
            j--;
    }

    cout << " LCS IS  ' " << str << " '" << endl;

    cout << "Shortest Supersequence is " << endl;
    i = 0;
    j = 0;
    l = 0;

    while(i < len1 && j < len2 && l < lcs_len) {
        if(str1[i] == str2[j] && str1[i] == str[l]){
            cout << str[l];
            i++;
            j++;
            l++;
        }
        else if(str1[i] == str[l]) {
            cout << str2[j];
            j++;
        }
        else if(str2[j] == str[l]){
            cout << str1[i];
            i++;
        }
        else {
            cout << str2[j] << str1[i];
            i++;
            j++;
        }
    }
}
int main()
{
    char str1[1000] , str2[1000];
    cin >> str1 >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    SCS(str1 ,len1 , str2 , len2);

return 0;
}
