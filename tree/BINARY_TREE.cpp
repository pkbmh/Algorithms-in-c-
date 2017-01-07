#include <bits/stdc++.h>
using namespace std;

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
}tree_node;

tree_node *create_newnode(int t) {
    tree_node *tmp = new tree_node;
    tmp->data = t;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}
tree_node *insert_node_in_tree(tree_node *root , int t) {
    tree_node *tmp = new tree_node;
    tmp->data = t;
    tmp->left = NULL;
    tmp->right = NULL;

    if(root == NULL)
        return tmp;

    queue <tree_node * > qu;
    tree_node *temp;
    qu.push(root);

    while(!(qu.empty())) {
       temp = qu.front();
        qu.pop();

        if(temp->left != NULL && temp->right != NULL) {
                qu.push(temp->left);
                qu.push(temp->right);
        }
        else
            break;
    }

    if(temp->left == NULL)
        temp->left = tmp;
    else
        temp->right = tmp;

    return root;
}
int height(tree_node *root) {
    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh > rh)
        return (lh+1);
    else
        return (rh+1);

}
void preorder(tree_node *root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(tree_node *root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorder(tree_node *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void levelorder(tree_node *root)
{
    if(root == NULL)
        return;

    queue < tree_node * > qu;

    cout << root->data << " ";

    if(root->left != NULL)
        qu.push(root->left);
    if(root->right != NULL)
        qu.push(root->right);

    while(!(qu.empty())) {
        tree_node *tmp = qu.front();
        qu.pop();
        cout << tmp->data << " ";

        if(tmp->left != NULL)
            qu.push(tmp->left);
        if(tmp->right)
            qu.push(tmp->right);

    }
    cout << endl;
}
void print_at_height(tree_node *root , int h) {
    if(root == NULL)
        return;
    if(h == 1)
        cout << root->data << " ";
    print_at_height(root->left , h-1);
    print_at_height(root->right , h-1);
}
void levelorder_recursive(tree_node *root) {
    int h = height(root);

    for(int i = 1; i <= h; i++)
        print_at_height(root , i);
}
/*
int main()
{
    tree_node *root = NULL;
    int n,t;
    cout << "Enter number of node" << endl;
    cin >> n;
    cout << "enter value of each node" << endl;
    while(n--) {
        cin >> t;
        root = insert_node_in_tree(root , t);
    }
    cout << "level order traversal " << endl;
    levelorder(root);

return 0;
}
*/
