#include<iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

struct Stack{
  Node *top;
  Stack() {
    top = NULL;
  }

  void insertLast(int data) {
    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
  }

  void removeFirst() {
    if(top == NULL) return;
    Node *temp = top;
    top = top->next;
    temp->next = NULL;
    delete temp;
  }

  void display() {
    Node *current = top;
    while (current != NULL) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
};

int main () {
  Stack stack;
  stack.insertLast(1);
  stack.insertLast(2);
  stack.insertLast(3);
  stack.removeFirst();
  stack.display();
  return 0;
}