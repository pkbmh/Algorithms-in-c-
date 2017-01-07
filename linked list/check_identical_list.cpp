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

bool is_identical(node *list1 , node *list2) {
    while(list1 != NULL && list2 != NULL) {
        if(list1->data != list2->data)
            return false;

        list1 = list1->next;
        list2 = list2->next;
    }

    if(list1 == NULL && list2  != NULL)
        return false;
    if(list1 != NULL && list2 == NULL)
        return false;

    return true;
}
int main()
{
    node *list1 = NULL;
    node *list2 = NULL;

    cout << "enter list1 (-1 for exit)" << endl;
    while(true) {
        int t;
        cin >> t;
        if(t == -1)
            break;

        list1 = insert_before(list1 , t);
    }
    while(true) {
        int t;
        cin >> t;
        if(t == -1)
            break;

        list2 = insert_before(list2 , t);
    }

    cout << " list 1 is ";
    traverse(list1);
    cout << " list 2 is ";
    traverse(list2);

    bool res = is_identical(list1 , list2);
    if(res)
        cout << "list are identical " << endl;
    else
        cout << "list are not identical " << endl;

return 0;
}
