#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
}node;

node *insert_before(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;

    while(ptr->next != NULL && ptr->next != root)
        ptr = ptr->next;

    tmp->next = root;
    ptr->next = tmp;

    return tmp;
}

node *insert_after(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;

    while(ptr->next != NULL && ptr->next != root)
        ptr = ptr->next;

    ptr->next = tmp;
    tmp->next = root;

    return root;
}

void traverse(node *root) {
    node *ptr = root;
    while(ptr != NULL && ptr->next != root) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    if(ptr != NULL)
    cout << ptr->data << "->" << ptr->next->data << endl;
}
node *insert_asce(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;
    node *pptr;
    while(ptr->next != NULL && ptr->next != root && ptr->data < t) {
        pptr = ptr ;
        ptr = ptr->next;
    }

    if(ptr == root) {
        if(ptr->next == NULL ){
        ptr->next = tmp;
        tmp->next = ptr;
        if(ptr->data > t)
            root = tmp;
        }
        else {
            node *end = ptr;
            while(end->next != ptr)
                end = end->next;

            tmp->next = ptr;
            end->next = tmp;
            root = tmp;
        }
    }
    else if(ptr->next == root){
        if(ptr->data < t) {
                ptr->next = tmp;
                tmp->next = root;
        }
        else {
            pptr->next = tmp;
            tmp->next = ptr;
        }
    }
    else {
        pptr->next = tmp;
        tmp->next = ptr;
    }
    return root;
}
node *insert_desc(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;

    if(root == NULL) {
        return tmp;
    }

    node *ptr = root;
    node *pptr;
    while(ptr->next != NULL && ptr->next != root && ptr->data > t) {
        pptr = ptr ;
        ptr = ptr->next;
    }

    if(ptr == root) {
        if(ptr->next == NULL ){
        ptr->next = tmp;
        tmp->next = ptr;
        if(ptr->data < t)
            root = tmp;
        }
        else {
            node *end = ptr;
            while(end->next != ptr)
                end = end->next;

            tmp->next = ptr;
            end->next = tmp;
            root = tmp;
        }
    }
    else if(ptr->next == root){
        if(ptr->data > t) {
                ptr->next = tmp;
                tmp->next = root;
        }
        else {
            pptr->next = tmp;
            tmp->next = ptr;
        }
    }
    else {
        pptr->next = tmp;
        tmp->next = ptr;
    }
    return root;
}

void delete_node(node *root , int nd) {
    if(nd == 1) {
        if(root->next == NULL || root->next == root) {
            cout << "only one node in list" << endl;
            exit(0);
        }
        root->data = root->next->data;
        node *dup = root->next;
        root->next = root->next->next;
        free(dup);
        return;
    }

    node *pptr = root;
    node *ptr = root->next;
    nd--;
    while(ptr != pptr && --nd)
      pptr = ptr , ptr = ptr->next;

    if(nd) {
        cout << "insufficient node in list " << endl;
        exit(0);
    }

    else {
        pptr->next = ptr->next;
        free(ptr);
    }

}
/*
int main()
{
    int t;
    node *root = NULL;
    cout << "Enter list (-1 to end) " << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        root = insert_after(root , t);
       //traverse(root);
    }
    cout << " list is " << endl;
    traverse(root);

    cout << "node to delete" << endl;
    int nd;
    cin >> nd;

    delete_node(root , nd);

    cout << "After deletion of node list is " << endl;
    traverse(root);

}
*/
