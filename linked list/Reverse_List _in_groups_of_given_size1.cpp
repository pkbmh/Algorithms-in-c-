#include <bits/stdc++.h>
#include "singly_list.cpp"
using namespace std;

node *reverse_in_group(node *root , int group_size)
{
    node *cur = root;
    node *next = NULL;
    node *prev = NULL;
    int i = group_size;

    while(cur != NULL && i--) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    if(next != NULL)
        root->next = reverse_in_group(next , group_size);

    return prev;
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
    cout << "Enter size of group " << endl;
    cin >> group_size;


    cout << "initial list is " << endl;
    traverse(root);

    root = reverse_in_group(root , group_size);
    cout << "After reverse list is " << endl;
    traverse(root);

return 0;
}
