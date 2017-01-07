#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

void print_at_k_distance(tree_node *root ,int k) {
    if(k < 0 || root == NULL)
        return;
    if(k == 0)
        cout << root->data << " ";

    print_at_k_distance(root->left , k-1);
    print_at_k_distance(root->right , k-1);
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of element in tree" <<endl;
    cin >> n;
    //srand(time(NULL));

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

    int k;
    cout << "Enter K " << endl;
    cin >> k;

    print_at_k_distance(root , k);
    cout << endl;

return 0;
}
