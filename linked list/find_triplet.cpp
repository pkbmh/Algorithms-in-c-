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

node *insert_asce(node *root , int t) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;
    node *pptr;

    while(ptr != NULL && ptr->data < t) {
            pptr = ptr;
            ptr = ptr->next;
    }
    if(ptr != root) {
        pptr->next = tmp;
        tmp->next = ptr;
    }
    else {
        tmp->next = root;
        root = tmp;
    }

    return root;
}

node *insert_desc(node *root , int t) {
   // cout << t << "nser" << endl;
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = t;
    tmp->next = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;
    node *pptr;
   // cout << "on while" << endl;
    while(ptr != NULL && ptr->data > t) {
           // cout << ptr->data << " ptr dta" << endl;
            pptr = ptr;
            ptr = ptr->next;
    }

    if(ptr != root) {
        pptr->next = tmp;
        tmp->next = ptr;
    }
    else {
        tmp->next = root;
        root = tmp;
    }

    return root;
}
void traverse(node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" << endl;
}

node *find_triplet(node *list1 , node *list2 , node *list3 , int sum) {
    node *res = NULL;

    node *plist1 = list1;
    node *plist2 = list2;
    node *plist3 = list3;
    int tsum;

    while(plist1 != NULL) {
        plist2 = list2;
        plist3 = list3;

        while(plist2 != NULL && plist3 != NULL) {
            tsum = plist1->data + plist2->data + plist3->data;

            if(tsum == sum) {
                res = insert_after(res , plist1->data);
                res = insert_after(res , plist2->data);
                res = insert_after(res , plist3->data);
                return res;
            }
            else if(tsum < sum)
                plist2 = plist2->next;
            else
                plist3 = plist3->next;
        }

        plist1 = plist1->next;
    }

    return res;
}

int main()
{
    node *list1, *list2 , *list3;
    list1 = list2 = list3 = NULL;
    int t;
    cout << "enter list 1 (-1 to end) " << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;

        list1 = insert_after(list1 , t);
    }

    cout << "enter list 2 (-1 to end) " << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;

        list2 = insert_asce(list2 , t);
    }

    cout << "enter list 3 (-1 to end) " << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;

        list3 = insert_desc(list3 , t);
    }
    int sum;
    cout << "enter triplet sum to find " << endl;
    cin >> sum;

    cout << "list 1 is ";
    traverse(list1);

    cout << "list 2 is in ascending order ";
    traverse(list2);

    cout << "list 3 is in descending order ";
    traverse(list3);

    node *triplet;
    triplet = find_triplet(list1 , list2 , list3 , sum);

    cout << "triplet is ";
    if(triplet == NULL)
        cout << "Not found any pair for triplet" << endl;
    else
        traverse(triplet);


return 0;
}
