#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(){
        data = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class doublylinkedlist{
    public:

    void insertAtTail(Node *&head){
        int data;
        cout << "enter value of data you want to insert at end: ";
        cin >> data;

        Node *temp = new Node(data);

        Node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->prev = ptr;
    }

    void printlinkedlist(Node *head){
        Node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void reverse(Node *current, Node *&head, Node *&temp){
        if(current->next == NULL){
            temp = current->next;
            head = current;
            return;
        }
        reverse(current->next, head, temp);
        current->next->next = current;
        current->next->prev = temp;
        temp = current->next;
    }

};

int main(){
    doublylinkedlist d;
    
    int num;
    cout << "how many numbers you want to enter in linked list: ";
    cin >> num;

    int data;
    cout << "enter data of first node: ";
    cin >> data;
    Node *head = new Node(data);

    for(int i=0; i<num-1; i++){
        d.insertAtTail(head);
    }

    d.printlinkedlist(head);

    Node *current = head;
    Node *temp = head;
    d.reverse(current, head, temp);
    current->next = NULL;
    current->prev = temp;

    d.printlinkedlist(head);

    return 0;
}