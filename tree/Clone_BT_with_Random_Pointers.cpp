#include <bits/stdc++.h>
using namespace std;

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *random;
}tree_node;

tree_node *create_newnode(int t) {
    tree_node *tmp = new tree_node;
    tmp->data = t;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->random = NULL;

    return tmp;
}
tree_node *create_manually() {
    tree_node *root = create_newnode(1);
    root->left = create_newnode(2);
    root->right = create_newnode(3);
    root->left->left = create_newnode(4);
    root->left->right = create_newnode(5);
    root->random = root->left->right;
    root->left->left->random = root;
    root->left->right->random = root->right;

    return root;
}
void inorder(tree_node *root) {
    if(root == NULL)
       return;
    inorder(root->left);
    cout << " [ "<< root->data << " , ";
    if(root->random == NULL)
        cout << "NULL]";
    else
        cout << root->random->data << "]   ";
    inorder(root->right);
}

tree_node *copy_left_right(tree_node *root , map < tree_node * , tree_node * > *mymap) {
    if(root == NULL)
        return NULL;
    tree_node *clone = create_newnode(root->data);
    (*mymap)[root] = clone;
    clone->left = copy_left_right(root->left , mymap);
    clone->right = copy_left_right(root->right , mymap);

    return clone;
}
void copy_random(tree_node *root , tree_node *clone , map < tree_node * , tree_node * > *mymap) {
    if(clone == NULL)
        return;
    clone->random = (*mymap)[root->random];
    copy_random(root->left , clone->left , mymap);
    copy_random(root->right , clone->right , mymap);
}
tree_node *clone_tree(tree_node *root) {
    if(root == NULL)
        return root;

    map < tree_node * , tree_node * > *mymap = new map < tree_node * , tree_node * >;
    tree_node *clone =  copy_left_right(root , mymap);
    copy_random(root , clone , mymap);

    return clone;
}
int main()
{
    tree_node *root = create_manually();
    cout << "root is (inorder) " << endl;
    inorder(root);
    cout << endl;

    tree_node *clone = clone_tree(root);
    cout << "clone is (inorder)" << endl;
    inorder(clone);

return 0;
}
