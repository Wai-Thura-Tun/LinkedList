#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

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
    printf("First Node Memory Address : %d\n", firstNode);
    printf("First node of next address : %d\n",firstNode->next);
    printf("Second Node Memory Address : %d\n", secondNode);
    printf("Second node of next address : %d\n",secondNode->next);
    printf("Third Node Memory Address : %d\n", thirdNode);
    printf("Third node of next address : %d\n",thirdNode->next);
    return 0;
}