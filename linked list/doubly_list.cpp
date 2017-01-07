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
node *insert_asce(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;
    node *pptr;

    while(ptr != NULL && ptr->data < t) {
            pptr = ptr;
            ptr = ptr->next;
    }
    if(ptr != root) {
        pptr->next = tmp;
        tmp->prev = pptr;
        tmp->next = ptr;
        if(ptr != NULL)
            ptr->prev = tmp;

    }
    else {
        tmp->next = root;
        root->prev = tmp;
        root = tmp;
    }

    return root;
}

node *insert_desc(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;
    node *pptr;

    while(ptr != NULL && ptr->data > t) {
            pptr = ptr;
            ptr = ptr->next;
    }
    if(ptr != root) {
        pptr->next = tmp;
        tmp->prev = pptr;
        tmp->next = ptr;
        if(ptr != NULL)
            ptr->prev = tmp;

    }
    else {
        tmp->next = root;
        root->prev = tmp;
        root = tmp;
    }

    return root;
}

void delete_node(node *root , int nd) {

    if(nd == 1) {
        if(root->next == NULL) {
            cout << "there is only one node in list " << endl;
            exit(0);
        }
        root->data = root->next->data;
        root->next = root->next->next;
        if(root->next != NULL)
            root->next->prev = root;
        return;
    }
    node *ptr = root;
    node *pptr;

    while(ptr != NULL && --nd) {
        pptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        cout << "insufficient node in list " << endl;
        exit(0);
    }
    pptr->next = ptr->next;
    if(pptr->next != NULL)
        pptr->next->prev = pptr;

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
/*

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

    cout << "traverse from left to right" << endl;
    traverse_right(root);
    node *ptr = root;

    while(ptr->next != NULL)
        ptr = ptr->next;        // finding last node;

    cout << "traverse from right to left " << endl;
    traverse_left(ptr);

    int nd;
    cout << "enter node to delete " << endl;
    cin >> nd; // nd'th node to delete;
    delete_node(root , nd);
    cout << "after deletioin of " << nd << " node " << "list is (left to right)" << endl;
    traverse_right(root);

    ptr = root;
     while(ptr->next != NULL)
        ptr = ptr->next;

cout << "after deletioin of " << nd << " node " << "list is (right to left)" << endl;    traverse_left(ptr);

return 0;
}
*/
