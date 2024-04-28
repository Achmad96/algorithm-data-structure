#include<iostream>
#include<string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string name){
        data = name;
        next = NULL;
    }
};

struct Queue{
    Node *front, *rear;
    Queue(){
        front = rear = NULL;
    }

    void insertFirst(string name) {
        Node *tmp = new Node(name);
        if (rear == NULL){
            front = rear = tmp;
            return;
        }
        rear->next = tmp;
        rear = tmp;
    }

    void removeFirst() {
        if (front == NULL) {
            cout << "The list is empty" << endl;
            return;
        }

		Node* tmp = front;
        front = front->next;

		if (front == NULL){
			rear = NULL;
		}

		delete tmp;
    }

    void printQueue() {
		Node* tmp =  front;
		while(tmp != NULL){
            cout << tmp->data << " "; 
            tmp = tmp->next;
		}
		cout << "\n" << endl;
    }
};

int main() {
    Queue q;
    q.insertFirst("Joko");
    // Joko
    q.insertFirst("Budi");
	// Joko Budi
	q.insertFirst("Edi");
	q.printQueue();
	// Joko Budi Edi
    q.removeFirst();
	// Budi Edi
    q.printQueue();
    return 0;
}
