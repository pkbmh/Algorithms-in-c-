/*
Given two sorted linked lists, construct a linked list that contains maximum sum path from start to end.
 The result list may contain nodes from both input lists. When constructing the result list,
 we may switch to the other input list only at the point of intersection
 (which mean the two node with the same value in the lists).
  You are allowed to use O(1) extra space.
example ::
List1 =  1->3->30->90->120->240->511
List2 =  0->3->12->32->90->125->240->249
Output: Following is maximum sum linked list out of two input lists
list =  1->3->12->32->90->125->240->511
we switch at 3 and 240 to get above maximum sum linked list
*/
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
void traverse(node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" << endl;
}
void intersection_point(node *list1 , node *list2 , vector < pair < node * , node * > >&intersection_p) {
    //node *res = NULL;

    while(list1 != NULL && list2 != NULL) {
            if(list1->data == list2->data) {
           //     res = insert_after(res , list1->data);
                intersection_p.push_back(make_pair(list1 , list2));
                list1 = list1->next;
                list2 = list2->next;

            }
            else if(list1->data < list2->data)
                list1 = list1->next;
            else
                list2 = list2->next;
    }
  //  return res;
}

node *max_sum_list(node *list1 , node *list2 ,  vector < pair < node * , node * > >&intersection_p , int ip_size) {
    node *result;

    int i = 0;
    node *ptr1 = list1;
    node *ptr2 = list2;
    node *tmp1 = list1;
    node *tmp2 = list2;
    int sum1 = 0;
    int sum2 = 0;
    while(i < ip_size) {
        sum1 = 0;
        sum2 = 0;
        while(ptr1 != NULL && ptr1 != intersection_p[i].first) {
            sum1 += ptr1->data;
            ptr1 = ptr1->next;
        }
        while(ptr2 != NULL && ptr2 != intersection_p[i].second) {
            sum2 += ptr2->data;
            ptr2 = ptr2->next;
        }

        if(i == 0)
            result = (sum1 > sum2) ? tmp1 : tmp2;
        else {
            if(sum1 > sum2)
                tmp2->next = tmp1->next;
            else
                tmp1->next = tmp2->next;
        }
        tmp1 = ptr1;
        tmp2 = ptr2;

        i++;
    }
    sum1 = 0;
    sum2 = 0;

    while(ptr1 != NULL) {
        sum1 += ptr1->data;
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL) {
        sum2 += ptr2->data;
        ptr2 = ptr2->next;
    }

    if(sum1 > sum2)
         tmp2->next = tmp1->next;
    else
         tmp1->next = tmp2->next;

    return result;
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

    vector < pair < node * , node * > > intersection_p;

    intersection_point(list1 , list2 , intersection_p);
     int ip_size = intersection_p.size();

    node *result = max_sum_list(list1 , list2 , intersection_p , ip_size);
    cout << "maximum sum list is " << endl;
    traverse(result);

    /*int i = 0;
    int size_v = intersection_p.size();

    node *ptr1 = list1;
    node *ptr2 = list2;

    while(i < size_v) {
            cout << "list1 ";
        while(ptr1 != NULL && ptr1 != intersection_p[i].first) {
            cout << ptr1->data << " ";
            ptr1 = ptr1->next;
        }
        cout << "| | list2 ";
        while(ptr2 != NULL && ptr2 != intersection_p[i].second) {
            cout << ptr2->data << " ";
            ptr2 = ptr2->next;
        }

        cout << endl;
        i++;
    }
    cout << "list1 ";
    while(ptr1 != NULL) {
        cout << ptr1->data << " ";
        ptr1 = ptr1->next;
    }

    cout << "list2 ";
    while(ptr2 != NULL) {
        cout << ptr2->data << " ";
        ptr2 = ptr2->next;
    }
   // cin >> i;
   */
return 0;
}

