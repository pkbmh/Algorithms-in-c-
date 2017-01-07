#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}node;

node *insert_before(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    tmp->next = root;
    root->prev = tmp;

    return tmp;
}

node *insert_after(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = tmp;
    tmp->prev = ptr;

    return root;
}

void traverse_right(node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" <<endl;
}
void traverse_left(node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->prev;
    }
    cout << "NULL" << endl;
}

void reverse(node **root) {
    node *cur , *tmp;
    cur = *root;
    tmp = NULL;

    while(cur != NULL) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }
    if(tmp != NULL)
        *root = tmp->prev;


}
int main()
{
    node *root = NULL;
    int t;
    while(true) {
        cin >> t;
        if(t == -1)
            break;

        root = insert_after(root , t);
    }

    cout << "list is ";
    traverse_right(root);

    reverse(&root);

    cout << "reverse list is " << endl;
    traverse_right(root);

return 0;
}
