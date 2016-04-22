// my first program in C++
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

void printNode(Node **node);
void printList(Node **head);
void addNode(Node *node, Node **head);
void addNodeAtIndex(int index, Node *node, Node **head);
void removeNode(Node *node, Node **head);
void removeNodeByLinux(Node *node, Node **head);
int main ()
{
    Node *head = NULL;
    Node *temp;
    for (int i = 1; i < 5; i++) {
        temp = new Node();
        temp->value = i;
        temp->next = NULL;
        addNode(temp, &head);
    }
    cout << "Singly linked list " << endl;
    printList(&head);
    Node *secondNode = head->next;
    removeNode(secondNode, &head);
    
    cout<<"Removed second node with normal solution" <<endl;
    printList(&head);
    
    cout << endl;
    cout<<"Add second node again" <<endl;
    addNodeAtIndex(1, secondNode, &head);
    printList(&head);
    
    secondNode = head->next;
    removeNodeByLinux(secondNode, &head);
    cout<<"Removed second node with Linux solution" <<endl;
    printList(&head);
}

void addNode(Node *node, Node **head) {
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void addNodeAtIndex(int index, Node *node, Node **head) {
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node **indirect = head;
    int count = 0;
    while (*indirect != NULL) {
        if (count == index) {
            node->next = *indirect;
            *indirect = node;
            break;
        }
        indirect = &(*indirect)->next;
        count++;
    }
}

void removeNode(Node *node, Node **head) {
    Node *prev = NULL;
    Node *temp = *head;
    while (temp != node) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = node->next;
    } else {
        prev->next = node->next;
    }
}

void removeNodeByLinux(Node *node, Node **head) {
    Node **indirect = head;
    while (*indirect != node) {
        indirect = &(*indirect)->next;
    }
    *indirect = node->next;
}


void printNode(Node **node) {
    Node *temp = *node;
    cout <<"Node: value=" << temp->value << ". node address:" << temp << ". node next address: " << temp->next << "  pointer next address:" << &(*node)->next << ". Memory of this pointer:" << (*node)->next << endl;
}

void printList(Node **head) {
    Node *temp = *head;
    while (temp != NULL) {
        printNode(&temp);
        temp = temp->next;
    }
}
