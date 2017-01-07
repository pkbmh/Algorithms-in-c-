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

node *merge_alternate(node *list1 , node *list2) {
    bool flag = false;
    node *pptr1 = list1;
    node *ptr1 = list1->next;
    node *pptr2 = list2;


    while(ptr1 != NULL) {
       pptr1->next = pptr2;
       pptr2 = pptr2->next;
       pptr1->next->next = ptr1;
       pptr1 = ptr1;
       ptr1 = ptr1->next;
    }

     if(pptr2 != NULL) {
        pptr1->next = pptr2;

        pptr2 = pptr2->next;
        pptr1->next->next = NULL;
     }
     return pptr2;
}
int main()
{
    node *list1 = NULL;
    node *list2 = NULL;

    int t;
    cout << "enter list1 (-1 to end)" << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;

        list1 = insert_after(list1 , t);
    }
    cout << "enter list2 (-1 to end) " << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;

        list2 = insert_after(list2 , t);
    }

    cout << "list1 is ";
    traverse(list1);
    cout << "list2 is ";
    traverse(list2);


    list2 = merge_alternate(list1 , list2);

    cout << "after merging list1 is " << endl;
    traverse(list1);
    cout << "after merging list2 is " << endl;
    traverse(list2);

return 0;
}
