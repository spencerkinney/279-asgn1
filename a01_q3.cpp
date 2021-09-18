#include <iostream>
#include <stack>
using namespace std;

template<class Object>
void printStack(stack<Object> *inputStack) {
    stack<Object> values = *inputStack; 
    while (!values.empty()) {
        cout << values.top() << ' ';
        values.pop();
    }
    cout << endl;
}

template<class Object>
Object removeSecond(stack<Object> *stk) {
    Object head = stk->top();
    stk->pop();
    Object removed = stk->top();
    stk->pop();
    stk->push(head);
    return removed;
}

int main() {
    stack<int> stack1;
    stack<int>* stackPtr = &(stack1);
    for (int i = 0; i < 8; i++) {
        int randNum = rand() % 100 + 1;
        stack1.push(randNum);
    }
    cout << "The random numbers that are pushed into the stack one by one: ";
    printStack(stackPtr);
    cout << "The data in the removed node is: ";
    cout << removeSecond(stackPtr) << endl;
    cout << "The updated stack is: ";
    printStack(stackPtr);
}