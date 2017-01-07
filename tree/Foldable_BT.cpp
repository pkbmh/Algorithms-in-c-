#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

bool is_foldable_util(tree_node *root1 , tree_node *root2) {
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;

    return (is_foldable_util(root1->left , root2->right) && is_foldable_util(root1->right , root2->left));
}
bool is_foldable(tree_node *root) {
    if(root == NULL)
        return true;

    return is_foldable_util(root->left , root->right);
}
tree_node *create_manually() {
    tree_node *root = create_newnode(1);
    root->left        = create_newnode(2);
    root->right       = create_newnode(3);
    root->left->right  = create_newnode(4);
    root->right->left = create_newnode(5);

    return root;
}
int main()
{
    tree_node *root = create_manually();
    cout << "Created tree is (levelorder)" << endl;
    levelorder(root);

    bool res = is_foldable(root);
    if(res)
        cout << "Tree is foldable " << endl;
    else
        cout << "Tree can't be fold" << endl;

return 0;
}
