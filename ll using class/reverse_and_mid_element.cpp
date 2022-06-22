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

    void printLinkedList(Node *&head){
        Node *ptr = head;
        while(ptr!=NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void reverse(Node *&head){
        Node *prev = NULL;
        Node *current = head;
        Node *temp;

        while(current != NULL){
            temp = current;
            current = current->next;
            temp->next = prev;
            prev = temp;
        }
        head = prev;
    }

    void reverseRecursion(Node *&current, Node *&head){
        if(current->next == NULL){
            head = current;
            return;
        }
        reverseRecursion(current->next, head);
        current->next->next = current;
        return;
    }

    void findmiddle(Node *&head){
        Node *slow = head;
        Node *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "mid element: " << slow->data << endl;
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

    s.reverse(head);
    s.printLinkedList(head);

    Node *current = head;
    s.reverseRecursion(current, head);
    current->next = NULL;
    s.printLinkedList(head);

    s.findmiddle(head);

    return 0;
}