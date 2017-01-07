#include <bits/stdc++.h>
using namespace std;

typedef struct AVL_node {
    int data;
    int height;
    struct AVL_node *left;
    struct AVL_node *right;
}AVL_node;

AVL_node *create_newnode(int t) {
    AVL_node *tmp = new AVL_node;
    tmp->data = t;
    tmp->height = 1;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

int height(AVL_node *root) {
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left) , height(root->right));
}
int node_height(AVL_node *root) {
    if(root == NULL)
        return 0;
    return root->height;
}
int get_balance(AVL_node *root) {
    if(root == NULL)
        return 0;
    return (node_height(root->left) - node_height(root->right));
}

AVL_node *left_rotate(AVL_node *root) {
    AVL_node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    root->height = max(node_height(root->left) , node_height(root->right)) + 1;
    tmp->height = max(node_height(tmp->left) , node_height(tmp->right)) + 1;

    return tmp;
}

AVL_node *right_rotate(AVL_node *root) {
    AVL_node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    root->height = max(node_height(root->left) , node_height(root->right)) + 1;
    tmp->height = max(node_height(tmp->left) , node_height(tmp->right)) + 1;

    return tmp;
}
AVL_node *insert_in_AVL(AVL_node *root , int t) {

    if(root == NULL)
        return create_newnode(t);
    if(root->data < t)
        root->right = insert_in_AVL(root->right , t);
    else
        root->left = insert_in_AVL(root->left , t);

    root->height  = 1 + max(node_height(root->left) , node_height(root->right));

    int balance = get_balance(root);
//    cout << "  balance  " << balance << "  t = " << t << " root " << root->data <<endl;

    // case1: left left unbalance
    if(balance > 1 && t <= root->left->data)
        return right_rotate(root);

    // case2: left right unbalance
    if(balance > 1 && t > root->left->data) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    //case3: right right unbalance
    if(balance < -1 && t > root->right->data)
        return left_rotate(root);

    //case4: right left unbalance
    if(balance < -1 && t <= root->right->data) {
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
void print_at_height(AVL_node *root , int h) {
    if(root == NULL)
        return;
    if(h == 1)
        cout << root->data << ":" << root->height << " , ";
    if(h > 1) {
        print_at_height(root->left , h-1);
        print_at_height(root->right , h-1);
    }
}
void levelorder(AVL_node *root) {
    int h = height(root);

    for(int i = 1; i <= h; i++) {
        cout << "At level " << i << " = ";
        print_at_height(root , i);
    cout << endl;
    }
    cout << endl;
}
AVL_node *min_val_node(AVL_node *root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}
AVL_node *delete_key(AVL_node *root , int key) {
    if(root == NULL)
        return root;
    if(root->data > key)
        root->left = delete_key(root->left , key);
    else if(root->data < key)
        root->right = delete_key(root->right , key);
    else {
       if(root->left == NULL || root->right == NULL) {
        AVL_node *tmp = (root->left == NULL) ? root->right : root->left;

        if(tmp == NULL) {
            tmp = root;
            root = NULL;
        }
        else
            *root = *tmp;

        free(tmp);
       }
       else { // both child are not NULL
            AVL_node *tmp = min_val_node(root->right);
            root->data = tmp->data;

            root->right = delete_key(root->right , tmp->data);

       }
    }
    if(root == NULL)
        return root;

    root->height = max(node_height(root->left) , node_height(root->right)) + 1;

    int balance = get_balance(root);

     // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left =  left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

return root;
}
int main()
{
    AVL_node *root = NULL;
    int n,t;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--) {
        //cin >> t;
        t = rand()%100;
        root = insert_in_AVL(root , t);
    }

    int h = height(root);
    cout << "Height of tree is = " << h << endl;

    cout << "Inorder traversal of tree is " << endl;
    inlorder(root);
    cout << endl;

    cout << "Enter key to be delete" << endl;
    int key;
    cin >> key;

    root = delete_key(root , key);
    cout << "After deletion of node tree is (inorder)" << endl;
    inorder(root);
    cout << endl;

    h = height(root);
    cout << "After deletion  height of tree is " << h << endl;
    levelorder(root);
return 0;
}

