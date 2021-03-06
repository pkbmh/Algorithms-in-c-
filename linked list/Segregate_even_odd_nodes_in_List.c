#include <bits/stdc++.h>
#include "singly_list.cpp"
using namespace std;

void segregate_list(node *root) {
    node *ptr ,*pptr ,*tmp;

    if(root->data%2 != 0) {
        ptr = root->next;
        while(ptr != NULL && ptr->data%2 != 0)
            ptr = ptr->next;
        if(ptr == NULL)
            return;
        else {
            int t = root->data;
            root->data = ptr->data;
            ptr->data = t;

        }
    }

    pptr = NULL;
    ptr = root;

    while(ptr != NULL && ptr->next != NULL) {
        if(ptr->next->data % 2 != 0) {
            tmp = ptr->next;
            ptr->next = ptr->next->next;


            ptr = ptr->next;

            tmp->next = pptr;
            pptr = tmp;
        }
        else
            ptr = ptr->next;
    }
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

   segregate_list(root);

    cout << "After rotation list is " << endl;
    traverse(root);

return 0;
}

