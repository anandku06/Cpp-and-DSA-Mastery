#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to delete a node from a doubly linked list
void deleteNode(Node** head_ref, Node* del) {
    // If the node to be deleted is null, return
    if (*head_ref == nullptr || del == nullptr)
        return;

    // If the node to be deleted is the head node
    if (*head_ref == del)
        *head_ref = del->next;

    // If the node to be deleted is not the last node
    if (del->next != nullptr)
        del->next->prev = del->prev;

    // If the node to be deleted is not the first node
    if (del->prev != nullptr)
        del->prev->next = del->next;

    // Free the memory of the node
    delete del;
}

// Utility function to insert a new node at the head of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;

    if (*head_ref != nullptr)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;
}

// Function to print the doubly linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
