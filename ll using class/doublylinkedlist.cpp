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
    void insertAtHead(Node *&head){
        int data;
        cout << "enter value of data you want to insert at head: ";
        cin >> data;

        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

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

    void insertAtpositions(Node *&head){    
        // head position = 1 and we want to insert at that position
        int position;
        cout << "enter value of position: ";
        cin >> position;
        if(position == 1){
            insertAtHead(head);
        }
        else if(position == getlength(head)+1){
            insertAtTail(head);
        }
        else{
            int data;
            cout << "enter value of data you want to insert at mid: ";
            cin >> data;
            Node *temp = new Node(data);

            Node *ptr = head;
            for(int i=0; i<position-2; i++){
                ptr = ptr->next;
            }

            temp->next = ptr->next;
            ptr->next = temp;
            temp->prev = ptr;
            temp->next->prev = temp;
        }
    }

    void deletefrombeginning(Node *&head){
        Node *temp = head;

        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
    }

    void deletefromend(Node *&head){
        Node *ptr = head;

        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }

        ptr->next->prev = NULL;
        ptr->next = NULL;
    }

    void deleteanyposition(Node *&head){
        int position;
        cout << "enter value of position: ";
        cin >> position;
        if(position == 1){
            deletefrombeginning(head);
        }
        else if(position == getlength(head)){
            deletefromend(head);
        }
        else{
            Node *ptr = head;
            for(int i=0; i<position-2; i++){
                ptr = ptr->next;
            }
            Node *temp = ptr->next;

            ptr->next = temp->next;
            temp->next = NULL;
            temp->prev = NULL;
            ptr->next->prev = ptr;
        }
    }

    void printlinkedlist(Node *head){
        Node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    int getlength(Node *head){
        Node *ptr = head;
        int len = 0;
        while(ptr != NULL){
            len = len + 1;
            ptr = ptr->next;
        }
        return len;
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

    d.insertAtpositions(head);
    d.printlinkedlist(head);

    d.deleteanyposition(head);
    d.printlinkedlist(head);


    return 0;
}