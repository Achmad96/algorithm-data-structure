struct Node{
  int value;
  Node* left;
  Node* right;

  Node(int value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class UndirectedGraph {
  Node* root;

  UndirectedGraph() {
    root = nullptr;
  }

  void addNode(int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
      root = newNode;
      return;
    }
    Node* current = root;
    while (current != nullptr) {
      if (current->value > value) {
        if (current->left == nullptr) {
          current->left = newNode;
          return;
        }
        current = current->left;
      } else {
        if (current->right == nullptr) {
          current->right = newNode;
          return;
        }
        current = current->right;
      }
    }
  }
};

class DirectedGraph {
  Node* root;

  DirectedGraph() {
    root = nullptr;
  }
};