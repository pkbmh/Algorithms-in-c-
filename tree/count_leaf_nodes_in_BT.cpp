#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;
void count_leaf(tree_node *root , int &leaf) {
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL) {
        leaf = leaf + 1;
        return;
    }
    count_leaf(root->left , leaf);
    count_leaf(root->right , leaf);

}
int main()
{
    tree_node *root = NULL;
    cout << "Enter number of node " << endl;
    int n;
    cin >> n;
    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "tree is levelorder " << endl;
    levelorder(root);

    int leaf = 0;
    count_leaf(root , leaf);
    cout << "Total leaf is " << leaf << endl;

return 0;
}
