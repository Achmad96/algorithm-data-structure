#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertLast(Node** head, int new_data)
{
    Node* new_node = new Node();
    Node* last = *head;
    
    new_node->next = NULL;
    new_node->data = new_data;
    
    if (*head == NULL) 
    {
        *head = new_node;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
}

void insertFirst(Node** head, int new_data) 
{
    Node* new_node = new Node();

    new_node->next = *head; 

    new_node->data = new_data;

    *head = new_node;
}

void insertAfter(Node** head, int checked, int new_data)
{
    if (head == NULL)
    {
        cout << "The list of the data is null" << endl;
        return;
    }

    Node* p = *head;
    Node* new_node = new Node;

    while (p != NULL) {
        if (p->data == checked) {
            new_node->data = new_data;
            new_node->next = p->next;

            p->next = new_node;
            return;
        }
        p = p -> next;
    }
    cout << "The data " << checked << " was not found in the list" << endl;
}

void showAllData(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


void deleteLast(Node** head)
{
    if (*head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }

    // *If there is only one node
    if ((*head)->next == NULL)
    {
        delete *head;
        *head = NULL;
        return;
    }

    // *else if there are more than one node
    Node* temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteFirst(Node** head) {
    if (*head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    Node* last = *head;
    if (last->next == NULL) {
        delete *head;
        *head = NULL;
        return;
    }
    *head = last->next;
}

void deleteAfter(Node** head, int checked) 
{
    if (*head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        cout << "The list only has one element" << endl;
        return;
    }

    Node* current = *head;
    while (current != NULL) {
        if (current->data == checked){
            Node* node_to_delete = current->next;
            current->next = node_to_delete->next;
            delete node_to_delete;
        }
        current = current->next;
    }
}

int main () 
{
    Node *head = NULL;
    insertLast(&head, 5);
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