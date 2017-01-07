#include <bits/stdc++.h>
#include "doubly_list.cpp"
using namespace std;

node *reverse_in_group(node *root , int group_size) {
    node *cur = root;
    node *next = NULL;
    node *previous = NULL;
    int i = group_size;

    while(cur != NULL && i--) {
        next = cur->next;
        previous = cur->prev;

        cur->prev = next;
        cur->next = previous;

        cur = next;
    }
    node *res;
    if(next != NULL) {
        next->prev = NULL;
        res = reverse_in_group(next , group_size);
        root->next = res;
        res->prev = root;
    }
    return previous->prev;

}

int main()
{

    int t;
    node *root = NULL;
    cout << "Enter list (-1 to end) " << endl;

    while(true) {
        cin >> t;
        if(t == -1)
            break;
        root = insert_after(root , t);
    }
    int group_size;

    cout << "Enter group size " << endl;
    cin >> group_size;

    cout << "Initial list is " << endl;
    traverse_right(root);

    root = reverse_in_group(root , group_size);

    cout << "After reverse list is " << endl;
    traverse_right(root);
return 0;
}
