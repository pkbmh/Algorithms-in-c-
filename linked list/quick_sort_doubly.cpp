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

    if(root == NULL)
        return tmp;

    tmp->next = root;
    root->prev = tmp;

    return tmp;
}

node *insert_after(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = tmp;
    tmp->prev = ptr;

    return root;
}
void traverse_right(node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" <<endl;
}
void traverse_left(node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->prev;
    }
    cout << "NULL" << endl;
}

node *partation(node *start , node *end) {
   //cout << " start " << start->data << " " << end->data << endl;
    node *pivot = start;
    node *ptr = start;
    int x = end->data;

    while(ptr != end) {
        if(ptr->data < x) {

            int tmp = ptr->data;
            ptr->data = pivot->data;
            pivot->data = tmp;
               pivot = pivot->next;
        }
        ptr = ptr->next;
    }

    end->data = pivot->data;
    pivot->data = x;

    return pivot;

}

void quick_sort(node *start , node *end) {
   // cout << start->data << " " << end->data << endl;
    if(start == end)
        return;

    node *pivot = partation(start , end);
    cout << "pivot " << pivot->data <<endl;

    if(pivot != start)
    quick_sort(start , pivot->prev);
    if(pivot != end)
    quick_sort(pivot->next , end);
}

int main()
{
    int t;
    node *root = NULL;
    cout << "Enter list (-1 to end)" << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        root = insert_after(root , t);
    }
    cout << "before sort list is " << endl;
    traverse_right(root);

    node *end;
    node *start = root;
    end = root;

    while(end->next != NULL)
        end = end->next;

    quick_sort(start , end);
    cout << "After sorting list is " << endl;
    traverse_right(root);

return 0;
}
