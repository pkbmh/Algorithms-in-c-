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

void pairwise_element_swap(node *root) {
   node *ptr,*pptr;
   pptr = root;
   ptr = root->next;
   int t;

   while(ptr != NULL) {
    t = pptr->data;
    pptr->data = ptr->data;
    ptr->data = t;

    pptr = ptr->next;
    if(pptr != NULL)
        ptr = pptr->next;
    else
        break;
   }
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

    pairwise_element_swap(root);
    cout << "after pairwise swap list is " << endl;
    traverse(root);

return 0;
}

