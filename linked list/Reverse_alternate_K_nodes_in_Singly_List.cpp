#include <bits/stdc++.h>
#include "singly_list.cpp"
using namespace std;

node *reverse_alternate_k_node(node *root , int k) {
    node *cur = root;
    node *prev = NULL;
    node *next = NULL;
    int i = k;

    while(cur != NULL && i--) {
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }
    if(next != NULL)
        root->next = next;

    i = k;

    while(next != NULL && i--){
        root = root->next;
        next = next->next;
    }

    if(next != NULL)
        root->next = reverse_alternate_k_node(next , k);

    return prev;
}
int main()
{
    node *root =  NULL;
    int t;
    while(true){
        cin >> t;
        if(t == -1)
            break;
        root = insert_after(root ,t);
    }
    int k;
    cout << "Enter K ";
    cin >> k;
    cout << "Initial list is " << endl;
    traverse(root);


    root = reverse_alternate_k_node(root , k);

    cout << "final list is " << endl;
    traverse(root);

return 0;
}
