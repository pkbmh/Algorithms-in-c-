#include <bits/stdc++.h>
using namespace std;

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *next_right;
}tree_node;

tree_node *insert_node_in_tree(tree_node *root , int t) {

    tree_node *tmp;
    tmp = (tree_node *)malloc(sizeof(tree_node));

    tmp->data = t;
    tmp->right = NULL;
    tmp->left = NULL;
    tmp->next_right = NULL;

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

    cout << endl;
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

void connect_node_at_same_level(tree_node *root) {
    queue < pair < tree_node * , int > >qu;
    int i = 1;

    if(root->left != NULL)
        qu.push(make_pair(root->left , i));
    if(root->right != NULL)
        qu.push(make_pair(root->right , i));

    pair < tree_node * , int > cur;
    tree_node *tt = NULL;
    cur = make_pair(tt , 0);
    pair < tree_node * , int > tmp;

    while(!(qu.empty())) {
        tmp = qu.front();
        qu.pop();

    //    cout << tmp.first->data << " ";

        if(cur.first != NULL && (cur.second == tmp.second))
            cur.first->next_right = tmp.first;

        cur = tmp;

        if(tmp.first->left != NULL)
            qu.push(make_pair(tmp.first->left , tmp.second+1));
        if(tmp.first->right != NULL)
            qu.push(make_pair(tmp.first->right , tmp.second+1));

    }

    cout << endl;
}

void levelorder_using_next_right(tree_node *root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    //levelorder_using_next_right(root->next_right);
    tree_node *ptr = root->next_right;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next_right;
    }

    levelorder_using_next_right(root->left);
}
int main()
{
    int n,t;
    tree_node *root = NULL;
    cout << "Enter number of node " << endl;
    cin >> n;

    cout << "Enter value of all node" << endl;
    while(n--) {
        cin >> t;
        root = insert_node_in_tree(root , t);
    }
    cout << "level order traversal of tree is " << endl;
    levelorder(root);

    connect_node_at_same_level(root);

    cout << "level order traversal using next_right" << endl;
    levelorder_using_next_right(root);
return 0;
}
