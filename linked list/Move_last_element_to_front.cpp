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

node *move_last_to_front(node *list1) {
    node *ptr = list1;
    node *pptr;

    while(ptr->next != NULL) {
        pptr = ptr;
        ptr = ptr->next;
    }

    pptr->next = NULL;
    ptr->next = list1;

    return ptr;
}
int main()
{
    node *list1 = NULL;

    int t;
    cout << "enter list (-1 to end)" << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;

        list1 = insert_after(list1 , t);
    }
    cout << "list is ";
    traverse(list1);

    list1 = move_last_to_front(list1);
    cout << "after move last to front " << endl;
    traverse(list1);

return 0;
}
