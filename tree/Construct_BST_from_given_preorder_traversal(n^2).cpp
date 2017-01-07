#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

int next_max(int pre[] , int l , int h) {
    int i;
    for(i = l+1;  i <= h; i++)
        if(pre[l] < pre[i])
            return i;
    return i;
}
tree_node *construct_tree(int pre[] , int l , int h) {
    if(l > h)
        return NULL;
    if(l == h)
        return create_newnode(pre[l]);

    tree_node *root = create_newnode(pre[l]);

    int nm = next_max(pre , l , h);
  //  cout << "nm " << nm << endl;
    root->left = construct_tree(pre , l+1 , nm-1);
    root->right = construct_tree(pre , nm , h);

    return root;
}

int main()
{
    int n;
    cout << "Enter number of node in tree" << endl;
    cin >> n;
    int pre[n];

    cout << "Enter preorder " << endl;
    for(int i = 0; i < n; i++)
        cin >> pre[i];

    tree_node *root = construct_tree(pre , 0 , n-1);
    cout << "Tree is (levelorder)" << endl;
    levelorder(root);

return 0;
}
