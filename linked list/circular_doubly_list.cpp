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

    if(root == NULL) {
        tmp->next = tmp;
        tmp->prev = tmp;
        return tmp;
    }

    node *ptr = root->prev;
    tmp->next = root;
    root->prev = tmp;
    tmp->prev = ptr;
    ptr->next = tmp;

    root = tmp;
    return root;
}

node *insert_after(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL) {
        tmp->next = tmp;
        tmp->prev = tmp;
        return tmp;
    }

    node *ptr = root->prev;
    ptr->next = tmp;
    tmp->prev = ptr;
    tmp->next = root;
    root->prev = tmp;

    return root;
}
void traverse_right(node *root) {
    node *ptr = root;
    while(ptr->next != NULL && ptr->next != root) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << ptr->data << "->" << ptr->next->data << "->NULL" << endl;
}
void traverse_left(node *root) {
    node *ptr = root;
    while(ptr->prev != NULL && ptr->prev != root) {
        cout << ptr->data << "->";
        ptr = ptr->prev;
    }
    cout << ptr->data << "->" << ptr->prev->data << "->NULL" << endl;
}

node *insert_asce(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL) {
        tmp->next = tmp;
        tmp->prev = tmp;
        return tmp;
    }

    node *pptr;
    node *ptr = root;

    while(ptr->next != root && ptr->data < t)
        pptr = ptr , ptr = ptr->next;

    if(ptr == root) {
        if(ptr->next == root) {
        ptr->next = tmp;
        tmp->prev = ptr;
        ptr->prev = tmp;
        tmp->next = ptr;
        if(t < ptr->data)
            root = tmp;
        }
        else {
            tmp->next = root;
            tmp->prev = root->prev;
            tmp->prev->next = tmp;
            root->prev = tmp;

            root = tmp;
        }
    }
    else if(ptr->next == root) {
        if(ptr->data < t) {
            ptr->next = tmp;
            tmp->prev = ptr;
            tmp->next = root;
            root->prev = tmp;
        }
        else {
            pptr->next = tmp;
            tmp->prev = pptr;
            ptr->prev = tmp;
            tmp->next  = ptr;
        }
    }
    else {
        pptr->next = tmp;
        tmp->prev = pptr;
        ptr->prev = tmp;
        tmp->next  = ptr;
    }

    return root;
}
node *insert_desc(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL) {
        tmp->next = tmp;
        tmp->prev = tmp;
        return tmp;
    }

    node *pptr;
    node *ptr = root;

    while(ptr->next != root && ptr->data > t)
        pptr = ptr , ptr = ptr->next;

    if(ptr == root) {
        if(ptr->next == root) {
        ptr->next = tmp;
        tmp->prev = ptr;
        ptr->prev = tmp;
        tmp->next = ptr;
        if(t > ptr->data)
            root = tmp;
        }
        else {
            tmp->next = root;
            tmp->prev = root->prev;
            tmp->prev->next = tmp;
            root->prev = tmp;

            root = tmp;
        }
    }
    else if(ptr->next == root) {
        if(ptr->data > t) {
            ptr->next = tmp;
            tmp->prev = ptr;
            tmp->next = root;
            root->prev = tmp;
        }
        else {
            pptr->next = tmp;
            tmp->prev = pptr;
            ptr->prev = tmp;
            tmp->next  = ptr;
        }
    }
    else {
        pptr->next = tmp;
        tmp->prev = pptr;
        ptr->prev = tmp;
        tmp->next  = ptr;
    }

    return root;
}

void delete_node(node *root , int nd) {
    if(nd == 1) {
        if(root->next == root) {
            cout << "only one node in list " << endl;
            exit(0);
        }
        root->data = root->next->data;
        node *dup = root->next;
        root->next = root->next->next;
        root->next->prev = root;

    return;
    }
    nd--;
    node *pptr;
    node *ptr = root->next;

    while(ptr != root && --nd)
        pptr = ptr , ptr = ptr->next;


    if(nd) {
        cout << "insufficient node in list " << endl;
        exit(0);
    }

    pptr->next = ptr->next;
    ptr->next->prev = pptr;



}
/*
int main()
{
    node *root = NULL;
    int t;
    cout << "enter list (-1 to end) " << endl;

    while(true) {
        cin >> t;
        if(t == -1)
            break;
        root = insert_after(root , t);
    }
    cout << "list is (root to next) " << endl;
    traverse_right(root);

    cout << "list is (root to left) " << endl;
    traverse_left(root);

    int nd;
    cout << "enter node to be delete " << endl;
    cin >> nd;

    delete_node(root , nd);
    cout << "After deletion of node list is (root to next) " << endl;
    traverse_right(root);
    cout << "After deletion of node list is (root to prev) " << endl;
    traverse_left(root);

return 0;
}
*/
