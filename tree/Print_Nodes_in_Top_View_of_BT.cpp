#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

void print_remaining_visible(tree_node *root , int ld , int rd , int d) {
    if(root == NULL)
        return;

    if(d < ld || d > rd)
        cout << root->data << " ";
    //cout << d << "  d  " << ld << " ld " << root->data << endl;
    print_remaining_visible(root->left , ld , rd , d-1);
    print_remaining_visible(root->right , ld , rd , d+1);
}
void print_top_view(tree_node *root) {
    if(root == NULL)
        return;

    tree_node *ptr = root;
    int ld = 0;
    int rd = 0;

    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->left;
        ld = ld-1;
    }
     ptr = root->right;
     rd = rd + 1;

     while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->right;
        rd = rd + 1;
     }
    print_remaining_visible(root , ld+1 , rd-1 , 0);
}
int main()
{
    tree_node *root = NULL;
    int n;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    root->left->right = create_newnode(25);
    root->left->right->left = create_newnode(26);
    root->left->right->left->left = create_newnode(27);
    root->left->right->left->left->left = create_newnode(28);

    cout << "tree is (level order) " << endl;
    levelorder(root);
    cout << endl;

    cout << "Top view of tree is " << endl;
    int level = 0;
    print_top_view(root);
    cout << endl;

return 0;
}

