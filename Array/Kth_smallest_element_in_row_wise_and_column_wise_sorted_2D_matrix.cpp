#include <bits/stdc++.h>
using namespace std;
#define row 4
#define col 4

typedef struct heap_node {
    int data;
    int r;
    int c;
}heap_node;
typedef struct min_heap {
    int capacity;
    int filled;
    heap_node *arr;
}min_heap;

heap_node create_heap_node(int val , int r , int c) {
    heap_node tmp;
    tmp.data = val;
    tmp.r = r;
    tmp.c = c;

    return tmp;
}
min_heap *create_min_heap(int  capacity) {
    min_heap *tmp = new min_heap;
    tmp->capacity = capacity;
    tmp->filled = 0;
    tmp->arr = new heap_node[capacity];

    return tmp;
}
void build_heap(min_heap *my_min_heap , int index) {
    int nexti = index;
    int n = my_min_heap->filled;
    int next = index*2;

    if(next+1 < n && my_min_heap->arr[next+1].data < my_min_heap->arr[nexti].data)
        nexti = next+1;
    if(next+2 < n && my_min_heap->arr[next+2].data < my_min_heap->arr[nexti].data)
        nexti = next+2;

    if(nexti != index) {
       // cout << my_min_heap->arr[index].data << " " << my_min_heap->arr[nexti].data << " "<<endl;
        heap_node tmp = my_min_heap->arr[nexti];
        my_min_heap->arr[nexti] = my_min_heap->arr[index];
        my_min_heap->arr[index] = tmp;

       build_heap(my_min_heap , nexti);
    }
}
void minheapify(min_heap *my_min_heap) {
    int  n = my_min_heap->filled-1;

    for(int i = n / 2; i >= 0; i--)
        build_heap(my_min_heap , i);
}
void insert_in_min_heap(min_heap *my_min_heap , int val , int r , int c) {
    if(my_min_heap->filled < my_min_heap->capacity) {
        int i = my_min_heap->filled;
        my_min_heap->arr[i] = create_heap_node(val , r , c);
        my_min_heap->filled++;
        // minheapify(my_min_heap);
    }
    else if(my_min_heap->arr[0].data > val){
            cout << "in else " << endl;
        my_min_heap->arr[0] = create_heap_node(val , r , c);
        //build_heap(my_min_heap);
        minheapify(my_min_heap);
    }
}
heap_node extract_heap_node(min_heap *my_min_heap) {
    heap_node tmp = my_min_heap->arr[0];
    my_min_heap->filled--;
    my_min_heap->arr[0] = my_min_heap->arr[my_min_heap->filled];

    minheapify(my_min_heap);

    return tmp;
}
int find_kth_smallest(int mat[row][col] , int k) {
    min_heap *my_min_heap;
    my_min_heap = create_min_heap(row);

    for(int i = 0; i < col ; i++)
        insert_in_min_heap(my_min_heap , mat[0][i] , 0 , i);

    minheapify(my_min_heap);

    heap_node tmp;

    for(int i = 0; i < k; i++) {
        tmp = my_min_heap->arr[0];

        int nextval = (tmp.r < (row-1)) ? mat[tmp.r+1][tmp.c] : INT_MAX;

        my_min_heap->arr[0] = create_heap_node(nextval , tmp.r+1 , tmp.c);
        minheapify(my_min_heap);
    }
    return tmp.data;
}
int main()
{
    int mat[row][col] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                    };

    int k = 7;

    int kth = find_kth_smallest(mat , k);
    cout << "7th smallest element is " << kth << endl;
return 0;
}
