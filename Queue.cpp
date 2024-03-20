#include<iostream>
#include<string>

using namespace std;

struct QNode {
    string data;
    QNode* next;
    QNode(string d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue{
    QNode *front, *rear;
    Queue(){
        front = rear = NULL;
    }
    void enque(string x) {
        QNode *tmp = new QNode(x);
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
        if (front == NULL) {
            rear = NULL;
        }

        delete tmp;
    }

    void printQueue() {
        while(rear != NULL){
            cout << rear->data << " " << endl;
            rear = rear->next;
        }
    }
};

int main() {
    Queue q;
    q.enque("Joko");
    // Joko
    q.enque("Budi");
    // Budi Joko 
    q.deque();
    // Budi
    q.printQueue();
    return 0;
}