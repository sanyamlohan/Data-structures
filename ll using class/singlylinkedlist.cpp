#include<iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node *next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int d){
        data = d;
        next = NULL;
    }
};

class Singlylinkedlist{
    public:
    void insertAtHead(Node *&head){        //use reference or change return type from void to Node * .
        int data;
        cout << "enter data which you want to insert at head: ";
        cin >> data;
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void insertAtTail(Node *&head){
        int data;
        cout << "enter data which you want to insert at end: ";
        cin >> data;
        Node *temp = new Node(data);
        
        Node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    void insertAtMiddle(Node *&head, int d){
        int data;
        cout << "enter data which you want to insert in middle: ";
        cin >> data;
        Node *temp = new Node(data);
        
        Node *ptr = head;
        while(ptr->data != d){
            ptr = ptr->next;
        }
        // after ptr we want to insert temp

        temp->next = ptr->next;
        ptr->next = temp;
    }

    void deleteFromBeginning(Node *&head){
        head = head->next;
    }

    void deleteFromEnd(Node *&head){
        Node *ptr = head;
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = NULL;
    }

    void deleteFromMiddle(Node *&head, int d){
        Node *ptr = head;
        while(ptr->next->data !=d){
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
    }

    void printLinkedList(Node *&head){
        Node *ptr = head;
        while(ptr!=NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main(){
    Singlylinkedlist s;
    int num;
    cout << "enter how many nodes you want to insert in linked list: ";
    cin >> num;

    int data;
    cout << "enter data of first node: ";
    cin >> data;
    Node *head = new Node(data);

    for(int i=0; i<num-1; i++){
        s.insertAtTail(head);
    }

    s.printLinkedList(head);

    return 0;
}