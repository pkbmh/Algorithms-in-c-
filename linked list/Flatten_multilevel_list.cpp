#include <bits/stdc++.h>
using namespace std;
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
typedef struct node {
    int data;
    struct node *next;
    struct node *child;
}node;

node *insert_after(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->child = NULL;

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

node *create_list(int arr[] , int s) {
    node *head = NULL;

    for(int i = 0; i < s; i++)
        head = insert_after(head , arr[i]);

    return head;
}

node *create_all_list() {
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};

    node *head1 = create_list(arr1 , SIZE(arr1));
    node *head2 = create_list(arr2 , SIZE(arr2));
    node *head3 = create_list(arr3 , SIZE(arr3));
    node *head4 = create_list(arr4 , SIZE(arr4));
    node *head5 = create_list(arr5 , SIZE(arr5));
    node *head6 = create_list(arr6 , SIZE(arr6));
    node *head7 = create_list(arr7 , SIZE(arr7));
    node *head8 = create_list(arr8 , SIZE(arr8));


    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;

    return head1;
}
void traverse_push(node *ptr , queue < node * > &qu , node **res) {
    while(ptr != NULL) {
        (*res) = insert_after(*res , ptr->data);
      //  cout << ptr->data << "->";
        if(ptr->child != NULL)
            qu.push(ptr->child);

        ptr = ptr->next;
    }
}
node *traverse_root_child(node *root) {
    node *ptr;
    node *res = NULL;
    queue < node * > qu;
    qu.push(root);
    while(!(qu.empty())) {
        node *ptr = qu.front();
        qu.pop();

        traverse_push(ptr , qu , &res);

    }
    return res;
    //cout << "NULL" << endl;
}

int main()
{
    node *root = NULL;

    root = create_all_list();

    cout << "after flatten of list final list is " << endl;
    node *result = traverse_root_child(root);
    traverse(result);

return 0;
}
