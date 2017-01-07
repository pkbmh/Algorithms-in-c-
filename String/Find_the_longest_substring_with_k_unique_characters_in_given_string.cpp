#include <bits/stdc++.h>
using namespace std;

bool is_valid(int *count , int k) {
    int val = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] > 0)
            val++;
    }
    return (val <= k);
}
void longest_substring(char *str , int len , int k) {
     int count[26];
    memset(count , 0, sizeof(count));
    int uni = 0;

    for(int i = 0; i< len; i++){
        if(count[str[i]-'a'] == 0)
            uni++;

        count[str[i]-'a']++;
    }
    if(uni < k) {
        cout << "Not possible " << endl;
        return;
    }

    memset(count , 0 , sizeof(count));

    count[str[0]-'a']++;
    int cur_start = 0;
    int cur_end = 0;
    int max_len = 0;
    int max_start  =0;
    int max_end = 0;

    for(int i = 1; i < len; i++) {
        count[str[i]-'a']++;
        cur_end++;

        while(!is_valid(count , k)) {
            count[str[cur_start]-'a']--;
            cur_start++;
        }

        if((cur_end-cur_start)+1 > max_len) {
            max_len = (cur_end-cur_start)+1;
            max_start = cur_start;
            max_end = cur_end;
        }
    }
    cout << max_start << " " << max_end <<endl;
    str = str+(max_start-1);
    cout << "Substring is : " << str << endl << " length is " << (max_len+1) << endl;
}
int main()
{
    char *str = "aabacbebebe";
    int len = strlen(str);
    int k = 2;

    longest_substring(str , len , k);

return 0;
}
