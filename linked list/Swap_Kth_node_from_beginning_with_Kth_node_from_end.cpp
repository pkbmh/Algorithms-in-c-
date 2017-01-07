#include <bits/stdc++.h>
#include "singly_list.cpp"
using namespace std;

node *swap_node(node *root , int k) {
    node *ptr,*tmp,*pptr ,*eptr,*epptr;

    eptr = NULL;
    epptr = NULL;
    ptr = root;
    pptr = NULL;
    int n = 1;
    while(ptr->next != NULL)
        n++ , ptr = ptr->next;

    cout << n << endl;

    int i = k;
    ptr = root;

    while(ptr != NULL && --i) {
        pptr = ptr;
        ptr = ptr->next;
    }

    i = n - k;

    if(i <= 0 || i == k)
        return root;

    eptr = root;
    while(eptr->next != NULL && i--) {
        epptr = eptr;
        eptr = eptr->next;
    }
    cout << eptr->data << " " << epptr->data << endl;
    if(pptr != NULL) {
    pptr->next = eptr;
    epptr->next = eptr->next;
    eptr->next = ptr->next;
    ptr->next = epptr->next;
    epptr->next = ptr;
    }
    else {
        eptr->next = ptr->next;
        ptr->next = NULL;
        epptr->next = ptr;
        root = eptr;
        }

    return root;
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
    int k;
    cout << "Enter K " << endl;
    cin >> k;

    cout << "Initial list is " << endl;
    traverse(root);

    root = swap_node(root , k);

    cout << "final list is " << endl;
    traverse(root);

return 0;
}
