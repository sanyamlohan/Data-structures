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

    void reverseInGroup(Node *&head, int k, Node *n, int &res){
        res = res + 1;
        Node *ptr = head;
        int x = k;
        while(x > 0 && ptr != NULL){
            ptr = ptr->next;
            x = x - 1;
        }
        Node *current = head;
        reverseK(head, current, ptr);
        current->next = ptr;
        if(ptr != NULL){
            if(res > 1){
                n->next = head;
            }
            reverseInGroup(ptr, k, current, res); 
        }
        else{
            if(res > 1){
                n->next = head;
            }
        }
    }

    void reverseK(Node *&head, Node *current, Node *ptr){
        if(current->next == ptr){
            head = current;
            return;
        }
        reverseK(head, current->next, ptr);
        current->next->next = current;
    }





    // 2nd solution

    Node * kreverse(Node *&head, int k){
        if(head == NULL){
            return NULL;
        }

        Node *current = head;
        Node *temp;
        Node *prev = NULL;

        int count = k;
        while(current != NULL && count > 0){
            temp = current;
            current = current->next;
            temp->next = prev;
            prev = temp;
            count--;
        }

        if(current != NULL){
            head->next = kreverse(current, k);
        }

        return prev;
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

    int res = 0;

    int k;
    cout << "enter k: ";
    cin >> k;
    
    // s.reverseInGroup(head, k, head, res);
    // s.printLinkedList(head);

    Node *n = s.kreverse(head, k);
    s.printLinkedList(n);

    return 0;
}