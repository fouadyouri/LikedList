#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

char menu(){
    char choice;

    cout << "Choose an option:\n";
    cout << "1. Add an element at the Begin of the LinkedList.\n";
    cout << "2. Add an element at the end of the LinkedList.\n";
    cout << "3. Remove an element.\n";
    cout << "4. Print the LinkedList.\n";
    cout << "5. Exit.\n";

    cin >> choice;
    return choice;
}

bool isEmpty(Node *head){
    if (head == NULL)
        return true;
    else
        return false;
}

void InsertFirstElement(Node *&head, Node *&last, int number){
    Node* temp = new Node;
    temp->data = number;
    temp->next = NULL;
    head = temp;
    last = temp;
}

void InsertAtEnd(Node *&head, Node *&last, int number){
    if(isEmpty(head))
        InsertFirstElement(head, last, number);
    else {
        Node* temp = new Node;
        temp->data = number;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void InsertAtBegin(Node *&head, Node *&last, int number){
    if(isEmpty(head))
        InsertFirstElement(head, last, number);
    else {
        Node* temp = new Node;
        temp->data = number;
        temp->next = head;
        head = temp;
    }
}

void InsertAtPosition(Node *&head, int number, int position){
    Node *temp1 = new Node;
    temp1->data = number;
    temp1->next = NULL;
    if(n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    for(int i = 0; i < n-2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Remove(Node *&head, Node *&last){
    if(isEmpty(head))
        cout << "The list is already empty.\n";
    else if (head == last) {
        delete head;
        head = NULL;
        last = NULL;
    }
    else {
        Node *temp = new Node;
        temp = head;
        head = head->next;
        delete temp;
    }
}

void Print(Node *current){
    if(isEmpty(current))
        cout << "The list is empty! \n" << endl;
    else {
        cout << "The list contains: \n";
        while(current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl << endl;
    }
}

int main(){
    Node *head = NULL;  //List is empty
    Node *last = NULL;

    char choice;
    int data;

    do{
        choice = menu();
        switch(choice) {
        case '1':
            cout << "Please input a number: ";
            cin >> data;
            InsertAtBegin(head, last, data);
            break;
        case '2':
            cout << "Please input a number: ";
            cin >> data;
            InsertAtEnd(head, last, data);
            break;
        case '3':
            Remove(head, last);
            break;
        case '4':
            Print(head);
            break;
        default:
            cout << "System exit.\n";
        }
    }while(choice != '5');

    return 0;
}
