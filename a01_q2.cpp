#include <iostream>
#include <list>
using namespace std;

template <class Object>
Object removeSmallest(list<Object> *ls) {
    list<Object> nums = *ls;
    int smallest;
    smallest = ls->front();
    for (auto current : nums) {
        if (current < smallest) {
            smallest = current;
        }
    }
    ls->remove(smallest);
    return smallest;
}

template <class Object>
void printList(list<Object> *ls) {
    list<Object> nums = *ls; 
    for (auto current : nums) {
        cout << current << ' ';
    }
    cout << endl;
}

int main() {
    list<int> numbers = {45, 25, 35, 10, 20, 30, 20, 10};
    list<int>* numberList = &(numbers);
    cout << "The original list: ";
    printList(numberList);
    cout << "List after removing the smallest elements:" << endl;
    cout << "The smallest value is: " << removeSmallest(numberList) << endl;
    cout << "List after removing the smallest elements: ";
    printList(numberList);
    return 0;
}