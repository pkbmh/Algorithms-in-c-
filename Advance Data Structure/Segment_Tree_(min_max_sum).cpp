#include <bits/stdc++.h>
using namespace std;

typedef struct segment_node {
    int minimum;
    int maximum;
    int sum;
}segment_node;

segment_node create_newnode(int mi , int ma , int s) {
    segment_node tmp;
    tmp.minimum = mi;
    tmp.maximum = ma;
    tmp.sum = s;
    return tmp;
}
segment_node combine(segment_node n1 , segment_node n2) {
    segment_node tmp;
    tmp.minimum = min(n1.minimum , n2.minimum);
    tmp.maximum = max(n1.maximum , n2.maximum);
    tmp.sum = (n1.sum + n2.sum);
    return tmp;
}
segment_node query_in_tree(segment_node tree[] , int l , int h , int indx , int p , int q) {
    if(p > h || q < l)
        return create_newnode(INT_MAX , INT_MIN , 0);
    if(p <= l && q >= h)
        return tree[indx];

    int next = 2 * indx;
    int mid  = (l + h) / 2;

    return ( combine(query_in_tree(tree , l , mid , next+1 , p , q) , query_in_tree(tree , mid+1 , h , next+2 , p , q)) );
}
void build_tree(segment_node tree[] , int arr[] , int indx ,int l , int h) {
    if(l == h) {
        tree[indx] = create_newnode(arr[l] , arr[l] , arr[l]);
        return;
    }
    int mid = (l + h) / 2;
    int next = 2 * indx;

    build_tree(tree , arr , next+1 , l , mid);
    build_tree(tree , arr , next+2 , mid+1 , h);

    tree[indx] = combine(tree[next+1] , tree[next+2]);
}
int main()
{
    int n;
    cout << "number of element in array" << endl;
    cin >> n;
    int arr[n];

    srand(time(NULL));
    cout << "Array is " << endl;
    for(int i = 0; i < n; i++) {
        int t = rand() % 100;
        cout << t << " ";
        arr[i] = t;
    }
    cout << endl;

    int h = (int)ceil(log2(n));
    int node = pow(2 ,h+1)-1;

    segment_node tree[node];

    build_tree(tree , arr ,0 ,  0 , n-1);

  /*  for(int i = 0; i < node; i++)
        cout << tree[i].minimum << " " << tree[i].maximum << " "<<tree[i].sum << endl;
    */
    while(true) {
    cout << "Enter range for query(to exit -1 -1)" << endl;
    int p,q;
    cin >> p >> q;

    segment_node res  = query_in_tree(tree , 0 , n-1 , 0 , p-1 ,q-1);
    cout << "Minimum over range is  " << res.minimum << endl;
    cout << "Maximum over range is  " << res.maximum << endl;
    cout << "Sum over range is  " << res.sum << endl;
    }
return 0;
}
