#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"
using namespace std;

void convert_into_mirror(tree_node *root) {
    queue < tree_node * > qu;
    qu.push(root);

    while(!(qu.empty())) {
        tree_node *tmp = qu.front();
        qu.pop();

        tree_node *t = tmp->right;
        tmp->right = tmp->left;
        tmp->left = t;

        if(tmp->right != NULL)
            qu.push(tmp->right);
        if(tmp->left != NULL)
            qu.push(tmp->left);
    }
}
void convert_into_mirror_recursive(tree_node *root) {
    if(root == NULL)
        return;
    convert_into_mirror_recursive(root->left);
    convert_into_mirror_recursive(root->right);

    tree_node *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "tree is (levleorder traversal)" << endl;
    levelorder(root);

    convert_into_mirror_recursive(root);
    convert_into_mirror(root);

    cout << "Mirror of tree is (level order traversal)" << endl;
    levelorder(root);

    cout << "Reconstruct tree from this mirror" << endl;
    convert_into_mirror(root);
    levelorder(root);

return 0;
}
