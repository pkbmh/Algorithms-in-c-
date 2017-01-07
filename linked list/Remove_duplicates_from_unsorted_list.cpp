#include <bits/stdc++.h>
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

void traverse(node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" << endl;
}

void remove_duplicates_unsorted(node *root) {
    node *ptr1 , *ptr2 , *dup;
    ptr1 = root;

    while(ptr1 != NULL) {
        node *pptr1 = ptr1;
        ptr2 = ptr1->next;

        while(ptr2 != NULL) {
            if(ptr2->data == ptr1->data) {
                dup = ptr2;
                ptr2 = ptr2->next;
                pptr1->next = ptr2;
                free(dup);
            }
            else {
                ptr2 = ptr2->next;
                pptr1 = pptr1->next;

            }
        }
        ptr1 = ptr1->next;
    }
}

int main()
{
    node *root = NULL;
    int t;
    cout << "Enter list (-1 to end) " << endl;

    while(true) {
        cin >> t;
        if(t == -1)
            break;

        root = insert_after(root , t);
    }

    cout << "list is " << endl;
    traverse(root);

    remove_duplicates_unsorted(root);

    cout << "After remove duplicate list is " << endl;
    traverse(root);

return 0;
}
