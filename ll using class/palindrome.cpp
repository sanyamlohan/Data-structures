#include<iostream>
using namespace std;

class Node;
class SinglyLinkedList;

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

class SinglyLinkedList{
    public:
    Node *head;
    SinglyLinkedList(){
        head = NULL;
    }
    SinglyLinkedList(Node *n){
        head = n;
    }

    void appendNode(Node *n){
        if(head == NULL){
            head = n;
            return;
        }
        Node *ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
    }

    void printList(){
        cout << "\nelements in linked list: ";
        Node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    void reverse_using_recursion(Node *current, Node *mid){
        if(current->next == NULL){
            mid->next = current;
            return;
        }
        reverse_using_recursion(current->next, mid);
        current->next->next = current;
    }

    Node * findmiddle(){
        Node *ptr = head;
        Node *ptr1 = head;

        while(ptr1->next != NULL && ptr1->next->next != NULL){
            ptr = ptr->next;
            ptr1 = ptr1->next->next;
        }

        cout << "middle element is: " << ptr->data << endl;
        return ptr;
    }

    void check_palindrome(){
        Node *ptr = head;
        Node *p = findmiddle();
        while(p->next != NULL){
            if(ptr->data == p->next->data){
                ptr = ptr->next;
                p = p->next;
            }
            else{
                cout << "Not palindrome" << endl;
                return;
            }
        }
        cout << "palindrome" << endl;
    }
};

int main(){
    SinglyLinkedList s;
    int num;
    cout << "enter the number of nodes: ";
    cin >> num;
    for(int i=0; i<num; i++){
        int data;
        cout << "\nenter data: ";
        cin >> data;
        Node *p = new Node(data);
        s.appendNode(p);
    }

    s.printList();
    cout << endl;

    Node *mid = new Node();
    mid = s.findmiddle();
    Node *current = mid->next; 
    s.reverse_using_recursion(current, mid);
    current->next = NULL;
    s.printList();
    cout << endl;

    s.check_palindrome();

}