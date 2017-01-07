#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"
using namespace std;

void print_left_view(tree_node *root , int &max_level , int cur) {
    if(root == NULL)
        return;
    if(cur > max_level) {
        cout << root->data << " ";
        max_level = cur;
    }
    print_left_view(root->left , max_level , cur+1);
    print_left_view(root->right , max_level , cur+1);

}
int main()
{
    tree_node *root = NULL;
    int n;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "tree is (level order) " << endl;
    levelorder(root);
    cout << endl;

    cout << "Left view of tree is " << endl;
    int level = 0;
    print_left_view(root , level , 1);
    cout << endl;

return 0;
}
