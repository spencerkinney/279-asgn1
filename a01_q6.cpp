#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
void add(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
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
   return 0;
}