/*
Given a binary string, count number of substrings that start and end with 1.
 For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.
*/
#include <bits/stdc++.h>
using namespace std;
#define max_len 100000

int countSubStr(char str[])
{
   int m = 0;
   for (int i=0; str[i] !='\0'; i++)
        if (str[i] == '1')
           m++;

   return m*(m-1)/2;
}

int count_substr(char str[] , int len) {
    int c1 = 0;
    int total_substr = 0;

    for(int i = (len-1); i >= 0; i--) {
        if(str[i] == '1') {
            c1 += 1;
            total_substr += c1 -1;
        }
    }
    return total_substr;
}

int main()
{
    char str[max_len];
    cout << "Enter binary string" << endl;
    cin >> str;
    int len = strlen(str);

    int total_substr = count_substr(str , len);
    cout << "Total possible sub-string start and end with 0 is " << endl;
    cout << total_substr << endl;

return 0;
}
