#include <bits/stdc++.h>
#include "singly_list.cpp"
using namespace std;

node *rotate(node *root , int k) {
    node *end_node = root;

    while(end_node->next != NULL)
        end_node = end_node->next;

    node *pptr = root;
    node *ptr = root->next;

    while(ptr != NULL && --k) {
        pptr = ptr;
        ptr = ptr->next;
    }
    pptr->next = NULL;
    end_node->next = root;

    return ptr;
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
    cout << "Enter Node for rotation" << endl;
    cin >> k;

    cout << "Initial list is " << endl;
    traverse(root);

    root = rotate(root , k);
    cout << "After rotation list is " << endl;
    traverse(root);

return 0;
}
