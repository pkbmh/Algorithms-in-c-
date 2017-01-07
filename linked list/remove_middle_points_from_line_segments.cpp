#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int x;
    int y;
    struct node *next;
}node;

node *insert_after(node *root , int x , int y) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->x = x;
    tmp->y = y;
    tmp->next = NULL;

    if(root == NULL)
        return tmp;

    node *ptr = root;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = tmp;

    return root;
}

node *insert_before(node *root , int x, int y) {
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->x = x;
    tmp->y = y;
    tmp->next = root;

    return tmp;
}

void traverse(node *root) {
    while(root != NULL) {
        cout << "("<< root->x << "," << root->y << ")" << "->";
        root = root->next;
    }
    cout << "NULL" << endl;
}

node *remove_middle_points(node *root) {
    node *ptr , *pptr;
    node *points = NULL;
    bool vl,hl,f;
    vl = hl = f = false;

    pptr = root;
    ptr = root->next;

    if(ptr->x == pptr->x)
        hl = true;
    else if(ptr->y == pptr->y)
        vl = true;

    points = insert_after(points , pptr->x , pptr->y);

    while(ptr->next != NULL) {
        pptr = ptr;
        ptr = ptr->next;
        if(vl == true && pptr->x == ptr->x && pptr->y != ptr->y) {
            if(!f)
                points = insert_after(points , pptr->x , pptr->y);

            points = insert_after(points , ptr->x , ptr->y);
            hl = true;
            vl = false;
            f = true;
        }
        else if(hl == true && pptr->y == ptr->y && pptr->x != ptr->x) {
            if(!f)
                points = insert_after(points , pptr->x , pptr->y);

            points = insert_after(points , ptr->x , ptr->y);
            vl = true;
            hl = false;
            f = true;
        }
        else {
             f = false;
        }

    }
    if(!f)
        points = insert_after(points , ptr->x , ptr->y);

    return points;
}

int main()
{
    node *root = NULL;
    int x,y;
    while(true) {
        cin >> x >> y;
        if(x == -1 && y == -1)
            break;

        root = insert_after(root , x , y);
    }
    cout << "Given line segment " << endl;
    traverse(root);

    node *after_remove = remove_middle_points(root);
    cout << " After remove middle element point is " << endl;
    traverse(after_remove);

return 0;
}
