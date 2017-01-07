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

void merge_sorted_list(node *list1 , node *list2) {
    bool flag = false;
    node *ptr,*pptr1,*pptr2;

    if(list1->data <= list2->data) {
        pptr1 = list1;
        ptr = list1->next;
        pptr2 = list2;
    }
    else {
        pptr1 = list2;
        ptr = list2->next;
        pptr2 = list1;
    }

    while(ptr != NULL && pptr2 != NULL) {
        if(ptr->data <= pptr2->data){
            pptr1->next = ptr;
            ptr = ptr->next;
            pptr1 = pptr1->next;
        }
        else {
            pptr1->next = pptr2;
            pptr2 = pptr2->next;
            pptr1 = pptr1->next;
        }

    }
    if(ptr != NULL)
        pptr1->next = ptr;
    if(pptr2 != NULL)
        pptr1->next = pptr2;

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


    merge_sorted_list(list1 , list2);

    cout << "after merging result list  is " << endl;
    traverse(list1);

return 0;
}
