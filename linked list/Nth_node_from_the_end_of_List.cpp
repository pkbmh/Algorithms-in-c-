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

node *nth_end_node(node *list1 , int n) {
    node *ptr = list1;
    int len = 0;
    while(ptr != NULL) {
        ptr = ptr->next;
        len++;
    }
    ptr = list1;
    int bn = len-n;

    while(bn--)
        ptr = ptr->next;

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

    int n;
    cin >> n;

    node *nth = nth_end_node(list1 , n);
    cout << "nth node from end is = " << nth->data << endl;

return 0;
}

