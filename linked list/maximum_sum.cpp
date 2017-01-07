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
node *intersection_point(node *list1 , node *list2 , vector < pair < node * , node * > >&intersection_p) {
    node *res = NULL;

    while(list1 != NULL && list2 != NULL) {
            if(list1->data == list2->data) {
                res = insert_after(res , list1->data);
                intersection_p.push_back(make_pair(list1 , list2));
                list1 = list1->next;
                list2 = list2->next;

            }
            else if(list1->data < list2->data)
                list1 = list1->next;
            else
                list2 = list2->next;
    }
    return res;
}
/*
int maximum_sum_list_rec(node *cur_list ,int num_list ,  int s ,int i , vector < pair < node * , node * > >&intersection_p , bool flip[]) {
    if(cur_list == NULL) {
            cout << "sum = " << s << " null " << endl;

        return s;
    }
    if(num_list == 1) {
            cout << "cur_list 1 " << cur_list->data << "sum = " << s <<endl;
        if(cur_list == intersection_p[i].first) {
            int sf = maximum_sum_list_rec(intersection_p[i].second->next , 2 , (s+cur_list->data) , i+1 , intersection_p , flip);
            int snf = maximum_sum_list_rec(cur_list->next , 1 , (s+cur_list->data) , i+1 , intersection_p , flip);

            if(sf > snf)
                flip[i] = true;

        }
        else return maximum_sum_list_rec(cur_list->next , 1 , (s+cur_list->data) , i , intersection_p , flip);
    }
    else {
             cout << "cur_list 2 " << cur_list->data << "sum = " << s << endl;
        if(cur_list == intersection_p[i].second) {
            int sf = maximum_sum_list_rec(intersection_p[i].first->next , 1 , (s+cur_list->data) , i+1 , intersection_p , flip);
            int snf = maximum_sum_list_rec(cur_list->next , 2 , (s+cur_list->data) , i+1 , intersection_p , flip);

            if(sf > snf)
                flip[i] = true;

        }
        else return maximum_sum_list_rec(cur_list->next , 2 , (s+cur_list->data) , i , intersection_p , flip);
    }
}
int maximum_sum_list(node *list1 , node *list2 , node *res , vector < pair < node * , node * > >&intersection_p , bool flip[]) {
    node *sum1;
    node *sum2;
    int ip_size = intersection_p.size();

    int s1 = 0;
    int s2 = 0;
    int i = 0;
    s1 = maximum_sum_list_rec(list1 , 1 , s1 ,  i , intersection_p , flip);
    s2 =  maximum_sum_list_rec(list2 , 2 , s2 , i , intersection_p , flip);

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    return (s1 > s2) ? 1 : 2;
}
*/
node *max_sum_list(node *list1 , node *list2) {
    node *cur1 = list1 , *pre1 = list1;
    node *cur2 = list2 , *pre2 = list2;
    node *result;

    while(cur1 != NULL || cur2 != NULL) {
        int sum1 = 0;
        int sum2 = 0;

        while(cur1 != NULL && cur2 != NULL && cur1->data != cur2->data) {
            if(cur1->data < cur2->data) {
                sum1 += cur1->data;
                cur1 = cur1->next;
            }
            else {
                sum2 += cur2->data;
                cur2 = cur2->next;
            }
        }

        if(cur1 == NULL) {
            while(cur2 != NULL) {
                    sum2 += cur2->data;
                    cur2 = cur2->next;
            }
        }
         if(cur2 == NULL) {
            while(cur1 != NULL) {
                    sum1 += cur1->data;
                    cur1 = cur1->next;
            }
        }

        if(pre1 == list1 && pre2 == list2)
            result = (sum1 > sum2) ? pre1 : pre2;
        else {
            if(sum1 > sum2)
                pre2->next = pre1->next;
            else
                pre1->next = pre2->next;
        }
        pre1 = cur1;
        pre2 = cur2;

        if(cur1 != NULL)
            cur1 = cur1->next;
        if(cur2 != NULL)
            cur2 = cur2->next;
    }

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

    node *result = max_sum_list(list1 , list2);
    cout << "maximum sum list is " << endl;
    traverse(result);

return 0;
}
