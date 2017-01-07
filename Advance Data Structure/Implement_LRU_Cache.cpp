#include <bits/stdc++.h>
//#include "doubly_list.cpp"
using namespace std;

typedef struct list_node {
    int data;
    struct list_node *next;
    struct list_node *prev;
}list_node;

list_node *insert_before(list_node *root , int t) {
    list_node *tmp;
    tmp = (list_node *)malloc(sizeof(list_node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    tmp->next = root;
    root->prev = tmp;

    return tmp;
}

list_node *insert_after(list_node *root , int t) {
    list_node *tmp;
    tmp = (list_node *)malloc(sizeof(list_node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    list_node *ptr = root;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = tmp;
    tmp->prev = ptr;

    return root;
}
list_node *insert_asce(list_node *root , int t) {
    list_node *tmp;
    tmp = (list_node *)malloc(sizeof(list_node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    list_node *ptr = root;
    list_node *pptr;

    while(ptr != NULL && ptr->data < t) {
            pptr = ptr;
            ptr = ptr->next;
    }
    if(ptr != root) {
        pptr->next = tmp;
        tmp->prev = pptr;
        tmp->next = ptr;
        if(ptr != NULL)
            ptr->prev = tmp;

    }
    else {
        tmp->next = root;
        root->prev = tmp;
        root = tmp;
    }

    return root;
}

list_node *insert_desc(list_node *root , int t) {
    list_node *tmp;
    tmp = (list_node *)malloc(sizeof(list_node));
    tmp->data = t;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(root == NULL)
        return tmp;

    list_node *ptr = root;
    list_node *pptr;

    while(ptr != NULL && ptr->data > t) {
            pptr = ptr;
            ptr = ptr->next;
    }
    if(ptr != root) {
        pptr->next = tmp;
        tmp->prev = pptr;
        tmp->next = ptr;
        if(ptr != NULL)
            ptr->prev = tmp;

    }
    else {
        tmp->next = root;
        root->prev = tmp;
        root = tmp;
    }

    return root;
}

void delete_list_node(list_node *root , int nd) {

    if(nd == 1) {
        if(root->next == NULL) {
            cout << "there is only one list_node in list " << endl;
            exit(0);
        }
        root->data = root->next->data;
        root->next = root->next->next;
        if(root->next != NULL)
            root->next->prev = root;
        return;
    }
    list_node *ptr = root;
    list_node *pptr;

    while(ptr != NULL && --nd) {
        pptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        cout << "insufficient list_node in list " << endl;
        exit(0);
    }
    pptr->next = ptr->next;
    if(pptr->next != NULL)
        pptr->next->prev = pptr;

}
void traverse_right(list_node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" <<endl;
}
void traverse_left(list_node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->prev;
    }
    cout << "NULL" << endl;
}

void  implement_LRU(int page_reference[] , int total_page , int cache_size , bool in_cache[]) {
    int i,j;

    list_node *front , *rear , *tmp;
    front = rear = NULL;

    front = insert_after(front , page_reference[0]);
    in_cache[page_reference[0]] = true;
   cout << "Page Fault Empty slot in cache new inserted page is:: " << page_reference[0] << endl;

    rear = front;

    int page_fault = 1;
    i = 1;
    j = 1;
    while(j < total_page) {
        if(in_cache[page_reference[j]] == true) { //page already in cache
            front = insert_after(front , page_reference[j]);
            front = front->next;
            cout << "page already in cache page is::" << page_reference[j] << endl;
            delete_list_node(rear , page_reference[j]);
        }
        else if(i >= cache_size){
            page_fault++;

            front = insert_after(front , page_reference[j]);
            front = front->next;

            tmp = rear;
            in_cache[page_reference[j]] = true;
            in_cache[tmp->data] = false;

            cout << "Page fault! Removed page is:: " << tmp->data << " New page is:: " << page_reference[j] << endl;
            rear = rear->next;
            free(tmp);
        }
        else {
            page_fault++;
            front = insert_after(front , page_reference[j]);
            front = front->next;

            cout << "Page fault!! Empty slot in cache new inserted page is:: " << page_reference[j] << endl;
            in_cache[page_reference[j]] = true;
            i++;
        }
        j++;
    }

    cout << "\n\tTotal page fault is " << page_fault << endl;
    cout << "\n\tFinal state of cache " << endl;
    cout << "\t";
    traverse_right(rear);

}
int main()
{
    int i,j;
    cout << "Enter size of cache " << endl;
    int cache_size;
    cin >> cache_size;

    cout << "Total number of referenced page " << endl;
    int total_page;
    cin >> total_page;

    int m = INT_MIN;
    int page_reference[total_page];

    cout << "Enter page number of referenced page " << endl;
    for(i = 0; i < total_page; i++) {
        cin >> page_reference[i];
        if(m < page_reference[i])
            m = page_reference[i];
    }
    bool in_cache[m+1];
    memset(in_cache , false , sizeof(in_cache));

    implement_LRU(page_reference , total_page , cache_size , in_cache);

return 0;
}
