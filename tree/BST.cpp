#include <bits/stdc++.h>
using namespace  std;

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

    tree_node *tmp;
    tmp = (tree_node *)malloc(sizeof(tree_node));

    tmp->data = t;
    tmp->right = NULL;
    tmp->left = NULL;

    if(root == NULL)
        return tmp;

    tree_node *ptr = root;
    tree_node *pptr;
    while(ptr != NULL) {
        pptr = ptr;
        if(ptr->data > t)
            ptr = ptr->left;
        else
            ptr = ptr->right;

    }
    (t > pptr->data) ? pptr->right = tmp : pptr->left = tmp;

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

    if(root->left != NULL)
        qu.push(root->left);
    if(root->right != NULL)
        qu.push(root->right);

    cout << root->data << " ";

    while(!(qu.empty())) {
        tree_node *tmp = qu.front();
        qu.pop();
        cout << tmp->data << " ";

        if(tmp->left != NULL)
            qu.push(tmp->left);
        if(tmp->right)
            qu.push(tmp->right);
    }
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
tree_node *delete_key(tree_node *root , int key)
{
    tree_node *ptr = root;
    tree_node *pptr = NULL;
    while(ptr != NULL && ptr->data != key)
    {
        pptr = ptr;
        if(ptr->data < key)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }

    if(ptr == NULL){
        cout << "key not in tree" << endl;
        exit(0);
    }

    if(ptr->left != NULL && ptr->right != NULL) {
            tree_node *tmp = ptr->right;
            tree_node *ptmp = NULL;

            while(tmp->left != NULL) {
                ptmp = tmp;
                tmp = tmp->left;
            }

            ptr->data = tmp->data;
       // dele_key(ptr->right , tmp->data);    without recursion change pointer ;

            if(ptmp != NULL)
                ptmp->left = tmp->right;
            else
                ptr->right = ptr->right->right;
    }
    else if(ptr->left != NULL) {
        if(pptr == NULL)
            root = ptr->left;
        else {
            if(ptr == pptr->left)
                pptr->left = ptr->left;
            else pptr->right = ptr->left;
        }
    }
    else if(ptr->right != NULL){
            if(pptr == NULL)
                root = ptr->right;
            else {
                if(ptr == pptr->left)
                    pptr->left = ptr->right;
                else
                    pptr->right = ptr->right;
            }
    }
    else
        root = NULL;

return root;
}
/*
int main()
{
    int t;
    tree_node *root = NULL;
    int n;
    cin >> n;
    while(n--) {
        t = rand()%100;
        cout << t << " ";
        root = insert_tree_node(root, t);
    }
    cout << endl;

    cout << "preorder traversal" << endl;
    preorder(root);
    cout << endl;

    cout << "postorder traversal " << endl;
    postorder(root);
    cout << endl;

    cout << "inorder traversal " << endl;
    inorder(root);
    cout << endl;

    int key;
    cout << "\n\n Enter key to delete " << endl;
    cin >> key;


    root = delete_key(root , key);

    cout << "After deletion preorder traversal " << endl;
    preorder(root);


return 0;
}
*/
