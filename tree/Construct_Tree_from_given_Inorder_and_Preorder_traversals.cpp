#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

int search_node(int in[] , int is, int ie , int data) {
    int i;
    for(i = is; i <= ie; i++)
        if(data == in[i])
            return i;
    return i;
}
tree_node *construct_tree(int in[] , int pre[] , int is , int ie) {
    static int indx;

    if(is > ie)
        return NULL;

    tree_node *root = create_newnode(pre[indx]);
    indx++;

    if(is == ie)
        return root;

    int indx_in = search_node(in , is , ie , pre[indx-1]);

    root->left = construct_tree(in, pre , is , indx_in-1);
    root->right = construct_tree(in , pre , indx_in+1 , ie);

    return root;
}

int main()
{
    int n;
    cout << "Enter number of node in tree" << endl;
    cin >> n;

    int pre[n] , in[n];

    cout << "Enter preorder " << endl;
    for(int i = 0; i < n; i++)
        cin >> pre[i];

    cout << "Enter inorder" << endl;
    for(int i = 0; i < n; i++)
        cin >> in[i];

    tree_node *root = construct_tree(in , pre , 0 , n-1);
    cout << "constructed tree is (levelorder)" << endl;
    levelorder(root);

return 0;
}
