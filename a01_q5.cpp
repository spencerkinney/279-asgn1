#include <iostream>
#include <list>
using namespace std;

template<class Object>
list<Object> listUnion(const list<Object> &L1, const list<Object> &L2) {
    list<Object> bigger;
    list<Object> smaller;
    if (L1.size() > L2.size()) {
        bigger = L1;
        smaller = L2;
    }
    else {
        bigger = L2;
        smaller = L1;
    }
    bigger.merge(smaller);
    bigger.sort();
    bigger.unique();
    return bigger;

}

template<class Object>
void printList(list<Object> L1) {
    for (auto n : L1) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    list<int> list1;
    list<int> list2;
    int randonNumber;
    for (int i = 0; i < 10; i++) {
        randonNumber = rand() % 100 + 1;
        list1.push_back(randonNumber);
        randonNumber = rand() % 100 + 1;
        list2.push_back(randonNumber);
    }
    list1.sort();
    cout << "The list1: ";;
    printList(list1);

    list2.sort();
    cout << "The list2: ";
    printList(list2);

    list<int> list3 = listUnion(list1, list2);
    cout << "The result set (union of list1 and list2): " << endl;
    printList(list3);
}