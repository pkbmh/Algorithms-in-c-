#include <bits/stdc++.h>
using namespace std;
#define max_len 10000

bool is_char(char c) {
    if(c >= 'a' && c <= 'z')
        return true;
    return false;
}

bool high_priority(char n , char t) {
    map < char , int > mymap;
    mymap.insert(make_pair('+' , 0));
    mymap.insert(make_pair('-' , 0));
    mymap.insert(make_pair('*' , 1));
    mymap.insert(make_pair('/' , 1));
    mymap.insert(make_pair('^' , 2));

    map < char , int >::iterator it1;
    map < char , int >::iterator it2;

    it1 = mymap.find(n);
    it2 = mymap.find(t);


    return (it2->second >= it1->second);
}
int main()
{
    char infix[max_len];
    cout << "Enter infix string " << endl;
    cin >> infix;

    stack < char > st;

    for(int i = 0; i < strlen(infix); i++) {

        if(is_char(infix[i]))
            cout << infix[i];
        else if(infix[i] == ')') {
               char t = st.top();
               st.pop();
               while(!st.empty() && t != '(') {
                        cout << t;
                        t = st.top();
                        st.pop();
                     }
        }
        else {
            char n = infix[i];


            while(!st.empty() && st.top() != '(' && high_priority(n , st.top())) {
                    char t = st.top();
                    cout << t;
                    st.pop();
                   // t = st.top();
                }
                  st.push(n);
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }

return 0;
}
