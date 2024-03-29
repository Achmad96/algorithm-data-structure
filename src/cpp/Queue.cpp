#include<iostream>
#include<string>

using namespace std;

struct QNode {
    string data;
    QNode* next;
    QNode(string name)
    {
        data = name;
        next = NULL;
    }
};

struct Queue{
    QNode *front, *rear;
    Queue(){
        front = rear = NULL;
    }

    void enque(string name) {
        QNode *tmp = new QNode(name);
        if (rear == NULL){
            front = rear = tmp;
            return;
        }
        rear->next = tmp;
        rear = tmp;
    }

    void deque() {
        if (front == NULL) {
            cout << "The list is empty" << endl;
            return;
        }

		QNode* tmp = front;
        front = front->next;

		if (front == NULL){
			rear = NULL;
		}

		delete tmp;
    }

    void printQueue() {
		QNode* tmp =  front;
		while(tmp != NULL){
				cout << tmp->data << " "; 
				tmp = tmp->next;
		}
		cout << "\n" << endl;
    }
};

int main() {
    Queue q;
    q.enque("Joko");
    // Joko
    q.enque("Budi");
	// Joko Budi
	q.enque("Edi");
	q.printQueue();
	// Joko Budi Edi
    q.deque();
	// Budi Edi
    q.printQueue();
    return 0;
}
