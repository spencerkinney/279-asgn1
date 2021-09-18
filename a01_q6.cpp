#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;

template<class Object>
void add(Object x) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = x;
   new_node->next = head;
   head = new_node;
}

template<class Object>
void remove(Object x) {
    struct Node* ptr;
    ptr = head;
    while (ptr != NULL) {
        ptr = ptr->next;
        if (ptr->data == x) {
            ptr->next = ptr->next->next;
        }
    }
}

void print() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

int size() {
   struct Node* ptr;
   ptr = head;
   int ctr = 0;
   while (ptr != NULL) {
       ptr = ptr->next;
       ctr++;
   }
   return ctr;
}

int main() {
   add(10);
   add(12);
   add(15);
   add(6);
   add(3);
   add(8);
   add(18);
   add(5);
   cout<<"The original linked list: ";
   print();
   cout << endl;
   cout << "The number of node in this list: " << size() << endl;
   remove(15);
   print();
   return 0;
}