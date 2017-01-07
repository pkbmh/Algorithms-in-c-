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

void reverse_append(node *root) {
    node *ptr , *pptr , *tmp;
    ptr = root;
    pptr = NULL;

    while(ptr != NULL && ptr->next != NULL){
            tmp = ptr->next;
            ptr->next = ptr->next->next;

            if(ptr->next != NULL)
                ptr = ptr->next;

            tmp->next = pptr;
            pptr = tmp;
    }

        ptr->next = pptr;

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

    cout << "initial list is " << endl;
    traverse(root);

    reverse_append(root);

    cout << "final list is " << endl;
    traverse(root);

return 0;
}
