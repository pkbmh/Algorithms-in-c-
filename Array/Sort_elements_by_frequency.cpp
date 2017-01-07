#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])


typedef struct DATA_FREQ {
    int index;
    int f;

    DATA_FREQ (int i , int d) {
        index = i;
        f = d;
    }

}DATA_FREQ;

bool comp(DATA_FREQ a , DATA_FREQ b) {
    return (a.f >= b.f);
}
void sort_by_frequency(int arr[] , int n) {
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
        max = (max < arr[i]) ? arr[i] : max;

    cout << max << endl;
    vector < DATA_FREQ > freq(max+1 , DATA_FREQ(0,0));

    for(int i = 0; i < n; i++){
        freq[arr[i]].index = arr[i];
        freq[arr[i]].f += 1;
    }



    sort(freq.begin() , freq.end(), comp);
    //for(int i = 0; i <= max; i++)
      //  cout << freq[i] << " : " << i << endl;

    cout << "array is (sorted by frequency)" << endl;
    for(int i = 0; i <= max; i++) {
        int f = freq[i].f;
        while(f != 0){
            cout << freq[i].index << " ";
            f--;
        }
    }
    cout << endl;
}


int main()
{
    int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
    int n = ARRAY_SIZE(arr);

    sort_by_frequency(arr , n);


return 0;
}
