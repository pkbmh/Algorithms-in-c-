#include <bits/stdc++.h>
using namespace std;

typedef struct interval {
    int low;
    int high;
    interval(int s , int e) {
        low = s;
        high = e;
    }
}interval;

typedef struct IVT_node {
    struct interval *i;
    int max;
    struct IVT_node *left;
    struct IVT_node *right;
}IVT_node;

IVT_node *create_newnode(interval t) {
    IVT_node *tmp = new IVT_node;
    tmp->i = new interval(t);
    tmp->max = t.high;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

IVT_node *insert_in_IVT_tree(IVT_node *root , interval t) {

    IVT_node *tmp = create_newnode(t);

    if(root == NULL)
        return tmp;

    IVT_node *ptr ,*pptr;
    ptr = root;
    while(ptr != NULL) {
        pptr = ptr;

        if(ptr->max < t.high)
            ptr->max = t.high;

        if(ptr->i->low > t.low)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if(pptr->i->low > t.low)
        pptr->left = tmp;
    else
        pptr->right = tmp;

    return root;

}
void inorder_IVT(IVT_node *root) {
    if(root == NULL)
        return;

    inorder_IVT(root->left);
    cout << "low " << root->i->low << " high " << root->i->high << " max = " << root->max << endl;
    inorder_IVT(root->right);
}
IVT_node *insert_in_IVT_tree1(IVT_node *root , interval t) {
    if(root == NULL)
        return create_newnode(t);

    if(t.low < root->i->low)
        root->left = insert_in_IVT_tree1(root->left , t);
    else
        root->right = insert_in_IVT_tree1(root->right , t);

    if(root->max < t.high)
        root->max = t.high;

    return root;
}
bool do_overlap(interval t1 , interval t2) {

    if (t1.low < t2.high && t2.low < t1.high)
        return true;
    return false;
}

interval *search_overlap(IVT_node *root , interval i) {
    if(root == NULL)
        return NULL;
    if(do_overlap(*(root->i) , i))
        return root->i;

    if(root->left != NULL && root->left->max >= i.high)
        return search_overlap(root->left , i);

    return search_overlap(root->right , i);
}

int main()
{
    interval appointments[] = { {1, 5} , {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100} };
    int ia_size = sizeof(appointments) / sizeof(appointments[0]);
    cout << ia_size << endl;
    IVT_node *root = NULL;

   for (int i = 0; i < ia_size; i++)
        root = insert_in_IVT_tree1(root, appointments[i]);

    cout << "inorder traversal of tree " << endl;
        inorder_IVT(root);
    cout << endl;


   for(int i = 0; i < ia_size; i++) {

        interval *ov =  search_overlap(root , appointments[i]);

        if(ov == NULL)
            cout << "No Overlapping interval for [" << appointments[i].low << "," << appointments[i].high << "]"  << endl;
        else
            cout << "interval [" << appointments[i].low << "," << appointments[i].high << "]" << "Overlap with "<< "["<< ov->low << "," << ov->high << "]" << endl;
    }

return 0;
}
