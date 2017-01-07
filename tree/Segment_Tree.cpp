#include <bits/stdc++.h>
using namespace std;

int query_in_tree(int tree[] , int l , int h , int indx , int p , int q) {
    if(h < p || l > q)
        return INT_MAX;
    if(p <= l && q >= h)
        return tree[indx];
    int next = 2 * indx;
    int mid = (l + h ) / 2;

    return min(query_in_tree(tree , l , mid , next+1 , p , q)  , query_in_tree(tree , mid+1 , h , next+2 , p , q) );

}
void build_tree(int tree[] , int arr[] , int indx , int l , int h) {
    if(l == h) {
        tree[indx] = arr[l];
        cout << indx << " "  << arr[l] << endl;
        return;
    }
    int next = 2 * indx;
    int mid = (l+h) / 2;

    build_tree(tree , arr , (next + 1) , l , mid);
    build_tree(tree , arr , (next + 2) , mid+1, h);

    tree[indx] = min(tree[next+1] , tree[next+2]);
}
int main()
{
    int n;
    cout << "number of element in array " << endl;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int height = (int)(ceil(log2(n)));
    int node = (int)pow(2 , height+1) - 1;

    int *tree = new int[node];
    for(int i = 0; i < node; i++)
        tree[i] = INT_MAX;
   // memset(tree , INT_MAX , sizeof(tree));

    cout << "node " << node << endl;
    build_tree(tree , arr , 0 , 0 , n-1);

    /*
    for(int i =0; i < node; i++)
        cout << tree[i] << " ";
    cout << endl;
    */

    int p , q;
    cout << "Enter range to query" << endl;
    cin >> p >> q;

    int res = query_in_tree(tree , 0 , n-1 , 0 , p-1 , q-1);
    cout << "minimum in [" << p << "," << q << "] = " << res << endl;

return 0;
}
