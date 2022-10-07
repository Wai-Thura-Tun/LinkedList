#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

void push(Node** firstNode,int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*firstNode);
    (*firstNode) = newNode;
}

void printNode(Node* node) {
    while (node != NULL) {
        printf("%d\t",node->data);
        node = node->next;
    }
}

void appendNode(Node** firstNode,int data) {
    Node* newNode = new Node();
    Node* last = (*firstNode);
    newNode->data = data;
    newNode->next = NULL;
    if (*firstNode == NULL) {
        *firstNode = newNode;
        return;
    }
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return;
}

void insertAfter(Node* after,int data) {
    if (after->next == NULL) {
        printf("Cannot insert node");
        return;
    }
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = after->next;
    after->next = newNode;
}

bool searchNode(Node* firstNode,int key) {
    Node* currentNode = firstNode;
    while(currentNode->next != NULL) {
        if (currentNode->data == key) {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

int main() {
    Node* firstNode = NULL;
    Node* secondNode = NULL;
    Node* thirdNode = NULL;

    firstNode = new Node();
    secondNode = new Node();
    thirdNode = new Node();
    firstNode->data = 1;
    firstNode->next = secondNode;

    secondNode->data = 3;
    secondNode->next = thirdNode;

    thirdNode->data = 4;
    thirdNode->next = NULL;

    push(&firstNode,100);
    push(&firstNode,120);
    appendNode(&firstNode,150);
    insertAfter(firstNode->next->next,140);
    bool searchResult = searchNode(firstNode,140);

//    printf("First Node Memory Address : %d\n", firstNode);
//    printf("First node of next address : %d\n",firstNode->next);
//    printf("Second Node Memory Address : %d\n", secondNode);
//    printf("Second node of next address : %d\n",secondNode->next);
//    printf("Third Node Memory Address : %d\n", thirdNode);
//    printf("Third node of next address : %d\n",thirdNode->next);
    printNode(firstNode);
    if (searchResult) {
        printf("Found node\n");
    }
    else {
        printf("Cannot found node\n");
    }
    return 0;
}