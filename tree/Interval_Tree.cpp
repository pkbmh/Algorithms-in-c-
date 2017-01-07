/*
Consider a situation where we have a set of intervals and we need following operations to be implemented efficiently.
 1) Add an interval
 2) Remove an interval
 3) GIVTen an interval x, find if x overlaps with any of the existing intervals.
 */

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

    if (t1.low <= t2.high && t2.low <= t1.high)
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

    interval ints[] = {{15, 20}, {10, 30}, {17, 19},
        {5, 20}, {12, 15}, {30, 40}
    };

    IVT_node *root = NULL;
    int n,s,e;
    cout << "Enter number of interval " << endl;
    //cin >> n;
    n = sizeof(ints)/sizeof(ints[0]);

    cout << "Enter each interval " << endl;


    for (int i = 0; i < n; i++)
        root = insert_in_IVT_tree1(root, ints[i]);

/*   while(n--) {
        cin >> s >> e;
        root = insert_in_IVT_tree(root , interval(s ,e));
    }
    */
    cout << "inorder traversal of tree " << endl;
    inorder_IVT(root);

    cout << "Enter a interval to find overlap interval" << endl;
    cin >> s >> e;

   interval *ov =  search_overlap(root , interval(s , e));
   if(ov == NULL)
    cout << "No Overlapping interval " << endl;
   else
    cout << "["<< ov->low << "," << ov->high << "]" << endl;

return 0;
}
