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

bool is_palindrome(node *list1 , node *list2) {

    while(list1 !=  NULL && list2 != NULL && list1->data == list2->data)
        list1 = list1->next , list2 = list2->next;

    if(list1 == NULL && list2 == NULL)
        return true;

    return false;

}
int main()
{
    node *list1 = NULL;
    node *list2 = NULL;
    int t;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        list1 = insert_after(list1 , t);
        list2 = insert_before(list2 , t);
    }
    bool res = is_palindrome(list1 , list2);
    if(res)
        cout << "list is palindrome" << endl;
    else
        cout << "list is not palindrome " << endl;

return 0;
}
