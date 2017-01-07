#include <bits/stdc++.h>
#include "singly_list.cpp"
using namespace std;

node *intersection(node *list1 , node *list2) {
    node *res = NULL;

    while(list1 != NULL) {
        node *ptr = list2;
        while(ptr != NULL) {
            if(ptr->data == list1->data) {
                res = insert_after(res , ptr->data);
                break;
            }
        ptr = ptr->next;
        }
        list1 = list1->next;
    }
    return res;
}

node *union_(node *list1, node *list2 , node *intersection_list) {
    node *res = list1;
    node *rptr = list1;
    node *start = res;

    while(res != NULL) {
        if(intersection_list != NULL && res->data == intersection_list->data) {
            cout << res->data << " ";
            if(res == rptr) {
                start = res->next;
                res = res->next;
                rptr = res;
                intersection_list = intersection_list->next;
                continue;
            }
            else {
                rptr->next = res->next;
                res = rptr->next;
            }
        }
        else {
            rptr = res;
            res = res->next;
        }
    }
    rptr->next = list2;
    return start;
}

int main()
{
    int t;
    node *list1 , *list2;
    list1 = list2 = NULL;

    cout << "enter first list (-1  to end)" << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        list1 = insert_after(list1 ,t);
    }
    cout << "enter second list(-1 to end)" << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        list2 = insert_after(list2 , t);
    }

    cout << "list 1 is ";
    traverse(list1);
    cout << "list 2 is ";
    traverse(list2);


    node *intersection_list = intersection(list1 , list2);

    cout << "intersection of these lists is " << endl;
    traverse(intersection_list);

    node *union_list = union_(list1 , list2 , intersection_list);

    cout << "Union of these list is " << endl;
    traverse(union_list);

return 0;
}
