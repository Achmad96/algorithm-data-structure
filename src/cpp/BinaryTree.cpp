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
  void insertTranversal(Node* &root, int value) {
    if (root == nullptr) {
      root = new Node(value);
      return;
    }
    if (value < root->data) insertTranversal(root->left, value);
    else insertTranversal(root->right, value);
  }

  void printPreOrderTranversal(Node* &node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    printPreOrderTranversal(node->left);
    printPreOrderTranversal(node->right);
  }

  void printInOrderTranversal(Node* &node) {
    if (node == nullptr) return;  
    printInOrderTranversal(node->left);
    cout << node->data << " ";
    printInOrderTranversal(node->right);
  }

  void printPostOrderTranversal(Node* &node) {
    if (node == nullptr) return;
    printPostOrderTranversal(node->left);
    printPostOrderTranversal(node->right);
    cout << node->data << " ";
  }

public:
  BinaryTree() {
    this->root = nullptr;
  }

  void insert(int data) {
    insertTranversal(this->root, data);
  }

  void printPreOrder() {
    printPreOrderTranversal(this->root);
    cout << endl;
  }

  void printInOrder() {
    printInOrderTranversal(this->root);
    cout << endl;
  }


  void printPostOrder() {
    printPostOrderTranversal(this->root);
    cout << endl;
  }
};

int main () {
  BinaryTree tree;
  tree.insert(10); // root
  tree.insert(5); // node left
  tree.insert(20); // node right

  tree.printPreOrder(); // 10 5 20
  tree.printInOrder(); // 5 10 20
  tree.printPostOrder(); // 5 20 10
  return 0;
}