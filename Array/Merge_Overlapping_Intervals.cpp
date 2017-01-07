#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])


typedef struct INTERVAL {
    int start;
    int end;
}INTERVAL;

bool comp(INTERVAL a , INTERVAL b) {
    return (a.start <= b.start);
}
void merge_overlapping(INTERVAL intervals[],  int n) {
    stack < INTERVAL > st;
    sort(intervals , intervals+n , comp);
    INTERVAL tmp;
    st.push(intervals[0]);

    for(int i = 1; i < n; i++) {
        tmp = st.top();

        if(intervals[i].end < tmp.start || intervals[i].start > tmp.end)
            st.push(intervals[i]);
        else {
            st.pop();
            tmp.start = min(tmp.start , intervals[i].start);
            tmp.end = max(tmp.end , intervals[i].end);
            st.push(tmp);
        }
    }

    while(!st.empty()){
        tmp = st.top();
        st.pop();

        cout << tmp.start << " " << tmp.end << endl;
    }
}
int main()
{
    INTERVAL intervals[] = {{6,8},{1,3},{2,4},{4,7}};
    int n = ARRAY_SIZE(intervals);

    merge_overlapping(intervals , n);

return 0;
}
