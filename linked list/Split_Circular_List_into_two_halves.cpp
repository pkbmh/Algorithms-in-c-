#include <bits/stdc++.h>
#include "circular_singly_list.cpp"
using namespace std;

pair < node * , node * > split_into_halves(node *root) {
    node *list1 , *list2;
    node *mid = root;
    node *ptr = root;
    while(ptr->next != root && ptr->next->next != root ) {
        ptr = ptr->next->next;
        mid = mid->next;
    }
    if(ptr->next->next == root)
        ptr = ptr->next;

    list1 = root;
    if(root->next != root)
        list2 = mid->next;

    ptr->next = mid->next;
    mid->next = root;

    return make_pair(list1 , list2);
}
int main()
{
    node *root = NULL;
    int t;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        root = insert_after(root , t);
    }
    cout << "given list is " << endl;
    traverse(root);

    pair < node * , node * > halves;

    halves = split_into_halves(root);

    cout << "first list is " << endl;
    traverse(halves.first);
    cout << "second list is  " << endl;
    traverse(halves.second);

return 0;
}
