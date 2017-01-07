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

node *pairwise_swap(node *root) {
    int t;
    node *ptr , *pptr,*tptr;

    pptr = root;
    tptr = root;
    ptr = pptr->next;
    root = ptr;


    while(ptr != NULL) {
        pptr->next = ptr->next;
        ptr->next = pptr;

        if(tptr != pptr)
            tptr->next = ptr;

        tptr = pptr;
        pptr = pptr->next;
        if(pptr != NULL)
            ptr = pptr->next;
        else
            break;
    }
    return root;
}
void traverse(node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" << endl;
}


int main()
{
    int t;
    node *root = NULL;

    cout << "enter list " << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        root = insert_after(root , t);
    }
    cout << "list is ";
    traverse(root);

    root = pairwise_swap(root);
    cout << "after pairwise swap list is " << endl;
    traverse(root);

return 0;
}
