#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

void print_bottom_view(tree_node *root) {
    vector < pair < tree_node * , int > >node_dist;

}
int main()
{
    int n;
    tree_node *root = NULL;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Tree is (levelorder)" << endl;
    levelorder(root);

    cout << "Bottom view of tree is " << endl;
    print_bottom_view(root);

return 0;
}
