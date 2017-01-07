#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
}node;

node *insert_after(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = tmp;

    return root;
}

node *insert_before(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = root;

    return tmp;
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

    while(ptr != NULL && ptr->data < t) {
            pptr = ptr;
            ptr = ptr->next;
    }
    if(ptr != root) {
        pptr->next = tmp;
        tmp->next = ptr;
    }
    else {
        tmp->next = root;
        root = tmp;
    }

    return root;
}

node *insert_desc(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;

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
        tmp->next = ptr;
    }
    else {
        tmp->next = root;
        root = tmp;
    }

    return root;
}
void delete_node(node *root , int nd) {
    if(nd == 1) {
        if(root->next == NULL){
            cout << "there is only one node in list " << endl;
            exit(0);
        }
        root->data =root->next->data;
        root->next = root->next->next;
        return;
    }

    node *ptr = root;
    nd--;
    while(ptr != NULL && --nd)
        ptr = ptr->next;

    ptr->next = ptr->next->next;

}
void traverse(node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->next;
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

    cout << "list is " << endl;
    traverse(root);
    int nd;
    cout << "enter node to delete " << endl;
    cin >> nd;

    delete_node(root , nd);
    cout << "after deletion list is " << endl;
    traverse(root);


return 0;
}
*/
