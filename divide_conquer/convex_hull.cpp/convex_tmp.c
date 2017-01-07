#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct point {
	int first;
	int second;
}point;

struct node
{
    int x, y;
    struct node *prev, *next;
};
/*void area(vector <pair <int , int> > v)
{


    int area;
    int temp_down,temp_up;
    temp_down = 0;
    temp_up = 0;
    for (int i = 0;i < v.size()-1; i++) {
        temp_down = temp_down + v[i].first*v[i+1].second;
        }

    for (int i = v.size()-1; i > 0; i--) {
            temp_up = temp_up + v[i].first * v[i-1].second;
    }
        //cout<<temp_down << "  " << temp_up << endl;
        cout<<(0.5)*fabs(temp_down-temp_up)<<endl;
}
*/
void print(struct node *head)
{
    struct node *tmp = head;
    struct node *temp1 = head;
    int cnt = 1;
    temp1= temp1->next;
    while(temp1 != head)
    {
        temp1 = temp1->next;
        cnt++;
    }
    //cout<<cnt<<endl;
    printf("%d\n", cnt);
    vector <pair <int , int > > v;
    do {
            v.push_back(make_pair(tmp->x, tmp->y));
        //cout << tmp->x << " " << tmp->y << endl;
        printf("%d %d\n", tmp->x , tmp->y);
        tmp = tmp->next;
    } while (tmp != head);
    area(v);
}

int check(int pos, int neg, int a, int b, int c)
{
    if (pos && neg)
        return -1;
    if (!pos && !neg)
        return 2;
    if (a != 0 && b != 0 && c != 0) {
        if (b > 0 && c > 0) {
            if (neg)
                return 0;
            else
                return 1;
        }
        else if (b > 0 && c < 0) {
            if (neg)
                return 0;
            else
                return 1;
        }
        else if (b < 0 && c > 0) {
            if (neg)
                return 1;
            else
                return 0;
        }
        else {
            if (neg)
                return 1;
            else
                return 0;
        }
    }
    else if (a != 0 && b != 0) {
        if (b > 0) {
            if (pos)
                return 1;
            return 0;
        }
        else {
            if (pos)
                return 0;
            return 1;
        }
    }
    else if (b != 0 && c != 0) {
        if (neg)
            return 0;
        return 1;
    }
    if (b > 0) {
        if (pos)
            return 1;
        return 0;
    }
    if (pos)
        return 0;
    return 1;
}

bool lies_in_mid(int x1, int y1, int x2, int y2, int x, int y)
{
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);
    if (x1 != x2) {
        if (x1 <= x && x <= x2)
            return true;
        return false;
    }
    if (y1 <= y && y <= y2)
        return true;
    return false;
}

struct node *merge(struct node *head1, struct node *head2, int l, int r)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *tmp1, *tmp2, *utl, *utr, *ltl, *ltr, *tmp3;
    int ut = 0, lt = 0;
    int x1, y1, x2, y2, x, y, tmp, a, b, c, neg, pos, oni, ono;
    tmp1 = head1;
    do {
        tmp2 = head2;

        do {

            x1 = tmp1->x;
            y1 = tmp1->y;
            x2 = tmp2->x;
            y2 = tmp2->y;

            a = y2-y1;
            b = x1-x2;
            c = x1*y2-x2*y1;
            if (a < 0) {
                a *= -1;
                b *= -1;
                c *= -1;
            }
            if (a == 0 && b < 0) {
                b *= -1;
                c *= -1;
            }

            neg = 0;
            pos = 0;
            oni = 0;
            ono = 0;



            tmp3 = head1;

            do {
                x = tmp3->x;
                y = tmp3->y;

                tmp = a*x+b*y-c;

                if (tmp > 0)
                    pos++;
                else if (tmp < 0)
                    neg++;
                else {
                    if (lies_in_mid(x1, y1, x2, y2, x, y))
                        oni++;
                    else
                        ono++;
                }
                tmp3 = tmp3->next;
            } while (tmp3 != head1);

            tmp3 = head2;

            do {
                x = tmp3->x;
                y = tmp3->y;

                tmp = a*x+b*y-c;

                if (tmp > 0)
                    pos++;
                else if (tmp < 0)
                    neg++;
                else {
                    if (lies_in_mid(x1, y1, x2, y2, x, y))
                        oni++;
                    else
                        ono++;
                }
                tmp3 = tmp3->next;
            } while (tmp3 != head2);

            if (!ono) {
                tmp = check(pos, neg, a, b, c);
                if (!ut && tmp == 0) {
                    utl = tmp1;
                    utr = tmp2;
                    ut = 1;
                }
                else if (!lt && tmp == 1) {
                    ltl = tmp1;
                    ltr = tmp2;
                    lt = 1;
                }
                else if (tmp == 2) {
                    ut = 1;
                    lt = 1;
                    ltl = tmp1;
                    ltr = tmp2;
                    utl = tmp1;
                    utr = tmp2;
                }
            }

            tmp2 = tmp2->next;

        } while (tmp2 != head2);
        tmp1 = tmp1->next;

    } while (tmp1 != head1);


    head->x = utl->x;
    head->y = utl->y;
    head->next = NULL;
    head->prev = NULL;

    struct node *tail = head;

    for (tmp1 = utr; tmp1 != ltr; tmp1 = tmp1->next) {
        struct node *ins = (struct node *)malloc(sizeof(struct node));
        ins->x = tmp1->x;
        ins->y = tmp1->y;
        ins->next = NULL;
        ins->prev = tail;
        tail->next = ins;
        tail = tail->next;
    }

    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->x = tmp1->x;
    ins->y = tmp1->y;
    ins->next = NULL;
    ins->prev = tail;
    tail->next = ins;
    tail = tail->next;

   for (tmp1 = ltl; tmp1 != utl; tmp1 = tmp1->next) {
        struct node *ins = (struct node *)malloc(sizeof(struct node));
        ins->x = tmp1->x;
        ins->y = tmp1->y;
        ins->next = NULL;
        ins->prev = tail;
        tail->next = ins;
        tail = tail->next;
    }
    head->prev = tail;
    tail->next = head;

    return head;
}

struct node *convex_hull(point v[], int l, int r)
{
    if ((r-l) == 1) {
        struct node *head = (struct node *)malloc(sizeof(struct node));
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        head->x = v[l].first;
        head->y = v[l].second;
        tmp->x = v[r].first;
        tmp->y = v[r].second;
        head->next = tmp;
        head->prev = tmp;
        tmp->next = head;
        tmp->prev = head;
        return head;
    }
    else if ((r-l) == 2) {
            struct node *head1, *head2, *head3;
            head1 = (struct node *)malloc(sizeof(struct node));
            head2 = (struct node *)malloc(sizeof(struct node));
            head3 = (struct node *)malloc(sizeof(struct node));

            int x1, y1, x2, y2, x3, y3, a, b, c, neg, pos, tmp;

            x1 = head1->x = v[l].first;
            y1 = head1->y = v[l].second;

            x2 = head2->x = v[l+1].first;
            y2 = head2->y = v[l+1].second;

            x3 = head3->x = v[r].first;
            y3 = head3->y = v[r].second;

            if ((y2-y1)*(x3-x2) == (y3-y2)*(x2-x1)) {
                head1->next = head3;
                head1->prev = head3;
                head3->next = head1;
                head3->prev = head1;
                return head1;
            }

            a = y3-y1;
            b = x1-x3;
            c = x1*y3-x3*y1;
            if (a < 0) {
                a *= -1;
                b *= -1;
                c *= -1;
            }
            else if (a == 0 && b < 0) {
                b *= -1;
                c *= -1;
            }

            neg = 0;
            pos = 0;

            if (a*x2+b*y2 < c)
                neg++;
            else
                pos++;
            tmp = check(pos, neg, a, b, c);
            if (tmp == 0) {
                head1->next = head3;
                head3->next = head2;
                head2->next = head1;
                head1->prev = head2;
                head3->prev = head1;
                head2->prev = head3;
                return head1;
            }
            head1->next = head2;
            head2->next = head3;
            head3->next = head1;
            head1->prev = head3;
            head2->prev = head1;
            head3->prev = head2;

            return head2;
    }
    else {
        struct node *tmp1, *tmp2;
        tmp1 = (struct node *)malloc(sizeof(struct node));
        tmp2 = (struct node *)malloc(sizeof(struct node));
        int m = (l+r)/2;
        tmp1 = convex_hull(v, l, m);
        tmp2 = convex_hull(v, m+1, r);
        return merge(tmp1, tmp2, l, r);
    }
}

void swap1(point *a , point *b) {
	int t = a->x;
	a->x = b->x;
	b->x = t;
}

void partation(int l , int h) 
{
	
	int x = v[h].x; // pivot
	int i = (l - 1); // Index of smaller element
	for (int j = l; j <= h- 1; j++)
	{
	if (v[j].x < x)
	{
	i++; // increment index of smaller element
	swap1(&v[i], &v[j]); // Swap current element with index
	}
}
swap1(&v[i+1], &v[h]);
return (i + 1);
}

void quick_sort(int l, int h)
{
	if(l >= h)
	return; 
	int p = partition(l, h); 
	quickSort(l, p - 1);
	quickSort(p + 1, h);
	 
	
}

int main()
{
    int n, i;
    cin>>n;
    
  //  vector < pair <int, int> > v(n);
    point v[n];
    
    for (i = 0; i < n; i++) {
        cin>>(v[i].first);
        cin>>(v[i].second);
    }
   
    quick_sort(v);
   
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = convex_hull(v, 0, n-1);
    print(head);
    return 0;
}
