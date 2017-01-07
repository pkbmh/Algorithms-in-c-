#include <bits/stdc++.h>
using namespace std;

typedef struct splay_node {
    int data;
    struct splay_node *left;
    struct splay_node *right;
}splay_node;

splay_node *create_newnode(int t) {
    splay_node *tmp = new splay_node;
    tmp->data = t;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

int height(splay_node *root) {
    if(root == NULL)
        return 0;
    return max(height(root->left) , height(root->right)) + 1;
}
splay_node *insert_in_splay(splay_node *root ,  int t) {
    if(root == NULL)
        return create_newnode(t);

    if(root->data < t)
        root->right = insert_in_splay(root->right , t);
    else
        root->left = insert_in_splay(root->left , t);

    return root;
}
void inorder(splay_node *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(splay_node *root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

splay_node *right_rotate(splay_node *root) {
    splay_node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    return tmp;
}

splay_node *left_rotate(splay_node *root) {
    splay_node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    return tmp;
}
splay_node *search_key(splay_node *root , int key) {
    if(root == NULL || root->data == key)
        return root;

    if(root->data > key) {

        if(root->left == NULL)
            return root;
        if(root->left->data > key) {
            root->left->left = search_key(root->left->left , key);

            root = right_rotate(root);
        }
        else if(root->left->data < key) {
            root->left->right = search_key(root->left->right , key);

            if(root->left->right != NULL)
                root->left = left_rotate(root->left);
        }
        return (root->left == NULL) ? root : right_rotate(root);
    }
    else {
        if(root->right == NULL)
            return root;
        if(root->right->data > key) {
            root->right->left = search_key(root->right->left , key);

            if(root->right->left != NULL)
                root->right = right_rotate(root->right);
        }
        else if(root->right->data < key){
            root->right->right = search_key(root->right->right , key);
            root = left_rotate(root);
        }
        return (root->right == NULL) ? root : left_rotate(root);
    }
}
int main()
{
    int n,t;
    splay_node *root = NULL;
    cout << "Enter number of node " << endl;
    cin >> n;

    cout << "Enter value of each node in tree " << endl;
    while(n--) {
        cin >> t;
        //t = rand()%100;
        root = insert_in_splay(root , t);
    }

    cout << "preorder traversal of tree is " << endl;
    preorder(root);
    cout << endl;

    int key;
    cout << "Enter key to search " << endl;
    cin >> key;

    root = search_key(root , key);
    cout << "preorder traversal of modified tree" << endl;
    preorder(root);
    cout << endl;

return 0;
}
