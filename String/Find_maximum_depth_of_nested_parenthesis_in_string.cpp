#include <bits/stdc++.h>
using namespace std;

int parenthesis_depth(char *str , int  len) {
    stack < char > st;
    int max_depth = INT_MIN;
    for(int i = 0; i < len; i++) {
        if(str[i] == '(')
            st.push(str[i]);
        else if(str[i] == ')') {
            if(!st.empty())
                st.pop();
            else
                return -1;
            }
        int t = st.size();
        max_depth = max(max_depth , t);
    }
    if(st.empty())
        return max(-1 , max_depth);
    else
        return -1;
}
int parenthesis_depth1(char *str , int len) {
    int c = 0;
    int max_depth = INT_MIN;

    for(int i = 0; i < len; i++) {
        if(str[i] == '(')
            c++;
        else if(str[i] == ')') {
            if(c == 0)
                return -1;
            c--;
        }
        max_depth = max(max_depth , c);
    }
    return max(max_depth , -1);
}
int main()
{
    char *str = "( a(b) (c) (d(e(f)g)h) I (j(k)l)m)"; // 4
    //char *str = "( p((q)) ((s)t) )"; // 3
    //char *str =  ""; //3
    //char *str = "b) (c) ()"; // -1
    //char *str = "(b) ((c) ()"; // -1
    int len = strlen(str);

    int depth = parenthesis_depth1(str , len);
    if(depth == -1)
        cout << "Not balanced " << endl;
    else
        cout << " Maximum depth : " << depth << endl;

return 0;
}
