#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

void print_next_greater(int arr[] , int n) {
    stack<int>st;
    st.push(arr[0]);

    for(int i = 1; i < n; i++) {
        int next = arr[i];

        if(!st.empty()) {
            int tmp = st.top();
            st.pop();

            while(tmp < next) {
                cout << tmp << "-->" << next << endl;
                if(st.empty())
                    break;

                tmp = st.top();
                st.pop();
            }
            if(tmp > next)
                st.push(tmp);
        }
        st.push(next);
    }
    while(!st.empty()) {
        cout << st.top() << "-->" << -1 << endl;
        st.pop();
    }
}
int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = ARRAY_SIZE(arr);

    print_next_greater(arr , n);

return 0;
}
