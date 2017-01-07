#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

int search_child(int parent[] , int l , int h , int r) {
    for(int i = l; i < h; i++)
        if(parent[i] == r)
            return i;
    return -1;
}
tree_node *create_tree(int parent[] , int r , int n) {
    if(r == -1)
        return NULL;
    tree_node *root = create_newnode(r);

    int lc = search_child(parent , 0 , n , r);
    int rc = search_child(parent , lc+1 , n , r);

    root->left = create_tree(parent , lc , n);
    root->right = create_tree(parent , rc , n);

    return root;
}
int main()
{
    int n;
    cout << "Enter total node " << endl;
    cin >> n;

    cout << "Enter parent array" << endl;
    int parent[n];
    int r;

    for(int i = 0; i < n; i++) {
        cin >> parent[i];
        if(parent[i] == -1)
            r = i;
    }

    tree_node *root = NULL;

    root = create_tree(parent , r , n);
    cout << "created tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

    int h = height(root);
    cout << "height is = " << h << endl;

return 0;
}
