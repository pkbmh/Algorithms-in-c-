#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

typedef struct AVL_node {
    int data;
    int height;
    int size;
    struct AVL_node *left;
    struct AVL_node *right;
}AVL_node;

AVL_node *create_newnode(int d) {
    AVL_node *tmp = new AVL_node;
    tmp->data = d;
    tmp->height = 1;
    tmp->size = 1;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

int height(AVL_node *root) {
    if(root == NULL)
        return 0;
    return root->height;
}
int get_size(AVL_node *root) {
    if(root == NULL)
        return 0;
    return root->size;
}
int is_balance(AVL_node *root) {
    if(root == NULL)
        return 0;
    return (height(root->left) - height(root->right));
}

int tree_size(AVL_node *root) {
    if(root == NULL)
        return 0;
    return (1+tree_size(root->left)+tree_size(root->right));
}
AVL_node *left_rotate(AVL_node *root) {
    AVL_node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    root->height = max(height(root->left) , height(root->right))+1;
    tmp->height = max(height(tmp->left) , height(tmp->right))+1;

    root->size = get_size(root->left) + get_size(root->right) + 1;
    tmp->size = get_size(tmp->left) + get_size(tmp->right) + 1;
    return tmp;
}
AVL_node *right_rotate(AVL_node *root) {
    AVL_node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    root->height = max(height(root->left) , height(root->right))+1;
    tmp->height = max(height(tmp->left) , height(tmp->right))+1;

    root->size = get_size(root->left) + get_size(root->right) + 1;
    tmp->size = get_size(tmp->left) + get_size(tmp->right) + 1;

    return tmp;
}
AVL_node *insert_node(AVL_node *root , int d , int *count_right) {
    if(root == NULL)
       return create_newnode(d);

    if(root->data > d)
        root->left = insert_node(root->left , d , count_right);
    else{
        root->right = insert_node(root->right , d , count_right);
        *count_right = *count_right + get_size(root->left)+1;
    }
    root->height = max(height(root->left) , height(root->right))+1;
    root->size = get_size(root->left) + get_size(root->right) + 1;

    int balance = is_balance(root);

    //cout << balance << "  d " << d << " root " << root->data << endl;

    //case1 left left unbalance
    if(balance > 1 && d < root->left->data)
        return right_rotate(root);

    // case 2 left right unbalance
    if(balance > 1 && d >= root->left->data){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    //case 2 right right unbalance
    if(balance < -1 && d >= (root->right->data))
        return left_rotate(root);

    // case 4 right left unbalance
    if(balance < -1 && d < root->right->data){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
void inorder(AVL_node *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    int arr[] = {10, 6, 15, 20, 30, 5, 7};
    int n = ARRAY_SIZE(arr);

    AVL_node *root = NULL;

    int *count_right = new int[n];
    for(int i = 0; i < n; i++)
        count_right[i] = 0;

    for(int i = n-1; i >= 0; i--)
        root = insert_node(root , arr[i] , &count_right[i]);

    //inorder(root);
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << count_right[i] << "  ";
    cout << endl;
return 0;
}
