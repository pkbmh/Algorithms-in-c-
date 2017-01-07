#include <bits/stdc++.h>
using namespace std;
#define max_len 10000

float get_evaluate(float f , float s , char ch) {
    switch(ch){
        case '+':
            return (f + s);
        case '-':
            return (s - f);
        case '*':
            return (s * f);
        case '/':
            return (s / f);
        case '^':
            return (float)(pow(s , f));
    }
}
float evaluate(char *postfix , int len) {
    stack < float > st;

    for(int i = 0; i < len; i++) {
        char ch = postfix[i];

        if(ch >= '0' && ch <= '9')
            st.push(ch-48);
        else {
            float f = st.top();
            st.pop();
            float s = st.top();
            st.pop();
            float res = get_evaluate(f , s , ch);
            st.push(res);
        }
    }

    return (st.top());
}

int main()
{
    char postfix[max_len];
    cout << "Enter postfix " << endl;
    cin >> postfix;

    int len = strlen(postfix);

    float res = evaluate(postfix , len);
    cout << "Result of  " << postfix <<" is = " << res << endl;

return 0;
}
