#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

template < class x > void swaper(x &a , x &b) { x t = a; a = b; b = t;}

class MIN_HEAP {
public:
    int size;
    int *arr;
    MIN_HEAP(int *p , int s);
    void heapify(int );
    int extract_element();
    int replace_and_extract(int );
};
MIN_HEAP::MIN_HEAP(int *p , int s) {
    this->size = s;
    this->arr = p;

    int i = (size-1) / 2;
    while(i >= 0) {
        heapify(i);
        i--;
    }

}
void MIN_HEAP::heapify(int x) {
    int next = x * 2;
    int i = x;
    if(next+1 < size && arr[next+1] < arr[i])
        i = next+1;
    if(next+2 < size && arr[next+2] < arr[i])
        i = next+2;
    if(i != x) {
        swaper(arr[i] , arr[x]);
        heapify(i);
    }
}

int MIN_HEAP::extract_element() {
    int root = arr[0];
    if(size > 1) {
        arr[0] = arr[size-1];
        size--;
        heapify(0);
    }
    return root;
}

int MIN_HEAP::replace_and_extract(int x) {
    int root = arr[0];
    arr[0] = x;
    if(root < x)
        heapify(0);

    return root;
}
void sort_k(int arr[] , int k , int n) {
    int *tmp = new int[k+1];
    int i,ti;

    for(i = 0; i < n && i <= k; i++)
        tmp[i] = arr[i];

    MIN_HEAP my_min_heap(tmp , k+1);

    for(i = k+1 , ti = 0; ti < n; i++ , ti++) {
        if(i < n)
            arr[ti] = my_min_heap.replace_and_extract(arr[i]);
        else
            arr[ti] = my_min_heap.extract_element();
    }

}
int main()
{
    int arr[] = {2, 6, 3, 12, 56, 8};
    int k = 3;
    int n = ARRAY_SIZE(arr);

    sort_k(arr ,k , n);

    cout << "Sorted array is " << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

return 0;
}
