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

node *intersection(node *list1 , node *list2) {
    node *res = NULL;

    while(list1 != NULL && list2 != NULL) {
            if(list1->data == list2->data) {
                res = insert_after(res , list1->data);
                list1 = list1->next;
                list2 = list2->next;

            }
            else if(list1->data < list2->data)
                list1 = list1->next;
            else
                list2 = list2->next;
    }
    return res;
}
int main()
{
    int t;
    node *list1 , *list2;
    list1 = list2 = NULL;

    cout << "enter first list (-1  to end)" << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        list1 = insert_after(list1 ,t);
    }
    cout << "enter second list(-1 to end)" << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        list2 = insert_after(list2 , t);
    }

    cout << "list 1 is ";
    traverse(list1);
    cout << "list 2 is ";
    traverse(list2);
    node *intersection_list = NULL;
    intersection_list = intersection(list1 , list2);

    cout << "intersection of these lists is " << endl;
    traverse(intersection_list);
return 0;
}
