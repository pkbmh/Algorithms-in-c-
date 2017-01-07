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
pair < node * , node * > partation(node *start , node *end) {
    node *pivot , *ppivot;
    pivot = start;
    ppivot = start;

    node *ptr = start;
    int x = end->data;

    while(ptr != end) {
        if(ptr->data < x) {

        }
    }
}
void quick_sort(node *start , node *end) {
    if(start == end)
        return;

    pair < node * , node * > pivot;

    pivot = partation(start , end);

    quick_sort(start , pivot.first)
    quick_sort(pivot.second , end);

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

    node *end = root;

    while(end->next != NULL)
        end = end->next;

    quick_sort(root);

    cout << "After sorting list is " << endl;

return 0;
}
