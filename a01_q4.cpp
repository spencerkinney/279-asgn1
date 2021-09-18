#include <iostream>
#include <queue>
using namespace std;

template<class Object>
void printQueue(queue<Object> *inputqueue) {
    queue<Object> values = *inputqueue; 
    while (!values.empty()) {
        cout << values.front() << ' ';
        values.pop();
    }
    cout << endl;
}

template<class Object>
Object removeSecond(queue<Object> *que) {
    queue<Object> values = *que;
    Object front = que->front();
    que->pop();
    Object removed = que->front();
    que-> pop();
    que->push(front);
    for (int i = 0; i < que->size()-1; i++) {
        front = que->front();
        que->push(front);
        que->pop();
    }
    return removed;
}

int sumEvenElements(queue<int> *que) {
    queue<int> values = *que;
    int sum = 0;
    while(!values.empty()) {
        if (values.front() % 2 == 0) {
            sum += values.front();
        }
        values.pop();
    }
    return sum;
}

int main() {
    queue<int> queue1;
    queue<int>* queuePtr = &(queue1);
    for (int i = 0; i < 10; i++) {
        int randNum = rand() % 50 + 1;
        queue1.push(randNum);
    }
    cout << "The random numbers that are pushed into the queue one by one: ";
    printQueue(queuePtr);
    cout << "The data in the removed node is: ";
    cout << removeSecond(queuePtr) << endl;
    cout << "The updated queue is: ";
    printQueue(queuePtr);
    cout << endl;
    cout << "The sum of the even elements is: " << sumEvenElements(queuePtr) << endl;
}