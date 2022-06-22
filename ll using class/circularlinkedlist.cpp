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

class circularlinkedlist{
    public:
    void insertAtHead(Node *&head){        //use reference or change return type from void to Node * .
        int data;
        cout << "enter data which you want to insert at head: ";
        cin >> data;
        Node *temp = new Node(data);

        Node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        temp->next = head;
        head = temp;
        ptr->next = head;
    }

    void insertAtTail(Node *&head){
        int data;
        cout << "enter data which you want to insert at end: ";
        cin >> data;
        Node *temp = new Node(data);
        
        Node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head;
    }

    void insertAtpositions(Node *&head){    
        // head position = 1 and we want to insert after position
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
        }
    }

    void deletefrombeginning(Node *&head){
        Node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }

        head = head->next;
        ptr->next = head;
    }

    void deletefromend(Node *&head){
        Node *ptr = head;
        while(ptr->next->next != head){
            ptr = ptr->next;
        }
        ptr->next->next = NULL;
        ptr->next = head;
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
            ptr->next = ptr->next->next;
        }
    }

    void printLinkedList(Node *&head){
        Node *ptr = head;
        cout << ptr->data << " ";
        ptr = ptr->next;
        while(ptr != head){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    int getlength(Node *head){
        Node *ptr = head;
        int len = 0;
        while(ptr->next != head){
            ptr = ptr->next;
            len = len + 1;
        }
        len = len + 1;
        return len;
    }
};

int main(){
    circularlinkedlist c;
    int num;
    cout << "enter how many nodes you want to insert in linked list: ";
    cin >> num;

    int data;
    cout << "enter data of first node: ";
    cin >> data;
    Node *head = new Node(data);
    head->next = head;

    for(int i=0; i<num-1; i++){
        c.insertAtTail(head);
    }

    c.printLinkedList(head);

    c.deleteanyposition(head);
    c.printLinkedList(head);

    return 0;
}