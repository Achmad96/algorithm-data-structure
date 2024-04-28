#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertLast(Node** head, int new_data){
    Node* last = *head;
    Node* new_node = new Node;

    new_node->next = NULL;
    new_node->data = new_data;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void insertFirst(Node** head, int new_data) {
    Node* new_node = new Node;
    new_node->next = *head;
    new_node->data = new_data;
    *head = new_node;
}

void insertAfter(Node** head, int checked, int new_data){
    if (head == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    Node* last = *head;
    Node* new_node = new Node;
    while (last != NULL){
        if (last->data == checked) {
            new_node->data = new_data;
            new_node->next = last->next;
            last->next = new_node;
        }
        last = last->next;
    }
}

void showAllData(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


void deleteLast(Node** head){
    if (*head == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    if ((*head)->next == NULL){
        delete *head;
        *head = NULL;
        return;
    }
    Node* last = *head;
    while (last->next->next != NULL) {
        last = last->next;
    }
    delete last->next;
    last->next = NULL;
}

void deleteFirst(Node** head) {
    if (*head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    if ((*head)->next == NULL){
        delete *head;
        *head = NULL;
        return;
    }
    Node* tmp = *head;
    *head = tmp->next;
    delete tmp;
    tmp = NULL;
}

void deleteAfter(Node** head, int checked) {
    if (*head == NULL){
        cout << "The list is empty" << endl;
        return;
    }

    if ((*head)->next == NULL){
        cout << "The list only has one element" << endl;
        return;
    }

    Node* last = *head;
    Node* tmp = new Node;
    while (last != NULL) {
        if (last->data == checked){
            tmp = last->next;
            last->next = tmp->next;
            delete tmp;
            tmp = NULL;
        }
        last = last->next;
    }
}

int main () {
    Node *head = NULL;
    insertFirst(&head, 5);
    // 5
    insertLast(&head, 10);
    // 5 10
    insertLast(&head, 7);
    // 5 10 7
    insertAfter(&head, 10, 3);
    // 5 10 3 7
    deleteLast(&head);
    // 5 10 3
    insertLast(&head, 7);
    // 5 10 3 7
    insertLast(&head, 7);
    // 5 10 3 7 7
    deleteFirst(&head);
    // 10 3 7 7
    deleteAfter(&head, 3);
    // 10 3 7
    insertLast(&head, 8);
    // 10 3 7 8
    insertLast(&head, 9);
    // 10 3 7 8 9
    deleteAfter(&head, 7);
    // 10 3 7 9

    showAllData(head);
    return 0;
}