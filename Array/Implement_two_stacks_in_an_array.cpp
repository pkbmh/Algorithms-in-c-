#include <bits/stdc++.h>
using namespace std;

class STACK {
    int size,*arr , top1 , top2;
public:
    STACK(int n) {
        size  = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int data) {
        if(top1 < top2-1)
            arr[++top1] = data;
        else
            cout << "Stack1 overflow" << endl;
    }
    void push2(int data) {
        if(top2 > top1+1)
            arr[--top2] = data;
        else
            cout << "Stack2 overflow" << endl;
    }
    int pop1() {
        if(top1 >= 0)
            return arr[top1--];
        else
            cout << "No element in stack1" << endl;
        return -1;
    }
    int pop2() {
        if(top2 < size)
            return arr[top2++];
        else
            cout << "No element in stack2" << endl;
        return -1;
    }
};
int main()
{
    STACK two_stack(5);
    two_stack.push1(19);
    two_stack.push1(10);
    two_stack.push1(11);
    two_stack.push2(12);
    two_stack.push2(13);
    two_stack.push1(112);
    two_stack.push2(333);

    cout << two_stack.pop1() << " " << two_stack.pop1() << " " << two_stack.pop1() << endl;
    two_stack.pop1();

    cout << two_stack.pop2() << " "  << two_stack.pop2() << endl;
    two_stack.pop2();

return 0;
}
