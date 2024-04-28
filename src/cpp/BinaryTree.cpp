#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

struct BinaryTree {
  Node* root;

private:
  void insertRecursive(Node* &node, int data) {
    if (node == nullptr) {
      node = new Node(data);
      return;
    }
    if (data < node->data) insertRecursive(node->left, data);
    else insertRecursive(node->right, data);
  }

  void printPreOrderRecursive(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    printPreOrderRecursive(node->left);
    printPreOrderRecursive(node->right);
  }

  void printInOrderRecursive(Node* node) {
    if (node == nullptr) return;  
    printInOrderRecursive(node->left);
    cout << node->data << " ";
    printInOrderRecursive(node->right);
  }

  void printPostOrderRecursive(Node* node) {
    if (node == nullptr) return;
    printPostOrderRecursive(node->left);
    printPostOrderRecursive(node->right);
    cout << node->data << " ";
  }

public:
  BinaryTree() {
    this->root = nullptr;
  }

  void insert(int data) {
    insertRecursive(this->root, data);
  }

  void printPreOrder() {
    printPreOrderRecursive(this->root);
    cout << endl;
  }

  void printInOrder() {
    printInOrderRecursive(this->root);
    cout << endl;
  }

  void printPostOrder() {
    printPostOrderRecursive(this->root);
    cout << endl;
  }
};

int main () {
  BinaryTree tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);

  tree.printPreOrder();
  // 10 20 30
  tree.printInOrder();
  // 10 20 30
  tree.printPostOrder();
  // 30 20 10
  return 0;
}