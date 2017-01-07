#include <bits/stdc++.h>
using namespace std;
typedef struct list_node {
    int data;
    struct list_node *next;
    struct list_node *prev;
}list_node;

list_node *insert_before(list_node *root , int t) {
    list_node *tmp;
    tmp = (list_node *)malloc(sizeof(list_node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    tmp->next = root;
    root->prev = tmp;

    return tmp;
}

list_node *insert_after(list_node *root , int t) {
    list_node *tmp;
    tmp = (list_node *)malloc(sizeof(list_node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    list_node *ptr = root;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = tmp;
    tmp->prev = ptr;

    return root;
}
list_node *insert_asce(list_node *root , int t) {
    list_node *tmp;
    tmp = (list_node *)malloc(sizeof(list_node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    list_node *ptr = root;
    list_node *pptr;

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

list_node *insert_desc(list_node *root , int t) {
    list_node *tmp;
    tmp = (list_node *)malloc(sizeof(list_node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    list_node *ptr = root;
    list_node *pptr;

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

void delete_list_node(list_node *root , int nd) {

    if(nd == 1) {
        if(root->next == NULL) {
            cout << "there is only one list_node in list " << endl;
            exit(0);
        }
        root->data = root->next->data;
        root->next = root->next->next;
        if(root->next != NULL)
            root->next->prev = root;
        return;
    }
    list_node *ptr = root;
    list_node *pptr;

    while(ptr != NULL && --nd) {
        pptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        cout << "insufficient list_node in list " << endl;
        exit(0);
    }
    pptr->next = ptr->next;
    if(pptr->next != NULL)
        pptr->next->prev = pptr;

}
void traverse_right(list_node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" <<endl;
}
void traverse_left(list_node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->prev;
    }
    cout << "NULL" << endl;
}
