#include <bits/stdc++.h>
#include "singly_list.cpp"
using namespace std;

node *add_number(node *num1 , node *num2) {
    int t , carry = 0;
    node *result = NULL;

    while(num1 != NULL && num2 != NULL) {
        t = num1->data + num2->data;
        t += carry;
        carry = t / 10;
        t = t % 10;

        result = insert_before(result , t);
        num1 = num1->next;
        num2 = num2->next;
    }
    while(num1 != NULL) {
        t = carry + num1->data;
        carry = t / 10;
        t = t % 10;
        result = insert_before(result , t);
        num1 = num1->next;
    }
    while(num2 != NULL) {
        t = carry + num2->data;
        carry = t / 10;
        t = t % 10;
        result = insert_before(result , t);
        num2 = num2->next;
    }
    if(carry)
        result = insert_before(result , t);

    return result;
}
void show_number(node *num)
{
    if(num == NULL)
        return;
    show_number(num->next);
    cout << num->data;
}
int main()
{
    node *num1 = NULL;
    node *num2 = NULL;
    int t;
    cout << "Enter first number (-1 to end) " << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        num1 = insert_before(num1 , t);
    }
    cout << "Enter second number (-1 to end ) " << endl;
    while(true) {
        cin >> t;
        if(t == -1)
            break;
        num2 = insert_before(num2 , t);
    }

    cout << "first number is = ";
    show_number(num1);
    cout << endl;
    cout << "second number is = ";
    show_number(num2);
    cout << endl;
    node *result = add_number(num1 , num2);
    cout << "addition is = ";
    traverse(result);
    cout << endl;

return 0;
}
