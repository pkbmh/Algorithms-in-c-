#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

int diameter(tree_node *root) {
    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max((1+lh+rh) , max(ld, rd));
}
int main()
{
    int n;
    tree_node *root = NULL;
    cout << "Enter number of node in tree " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Created tree is levelorder" << endl;
    levelorder(root);

    int dia = diameter(root);
    cout << "diameter of tree is " << dia << endl;

return 0;
}
