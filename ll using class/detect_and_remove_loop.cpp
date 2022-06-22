#include<bits/stdc++.h>
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

    void detectloop(Node *head, map<int, int> &m, Node *&cycle){
        Node *ptr = head;
        m[ptr->data] = 1;
        while(ptr->next != NULL){
            if(m[ptr->next->data] == 1){
                cycle = ptr;
                cout << "loop present" << endl;
                return;
                break;
            }
            m[ptr->next->data] = 1;
            ptr = ptr->next;
        }
        cout << "loop not found" << endl;
    }

    void floydCycleDetection(Node *head, Node *&slow, Node *&fast){

        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;

            if(fast!=NULL){
                fast = fast->next;
            }

            if(slow == fast){
                cout << "loop present" << endl;
                return;
            }
        }
        if(fast == NULL){
            cout << "loop not present" << endl;
        }
    }

    void beginningNodeOfLoop(Node *head, Node *&slow, Node *&fast){
        slow = head;
        // before remove the loop we run this code
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(slow == fast){
                cout << slow->data << endl;
                return;
            }
        }
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


    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = head->next->next;

    map <int, int> m;
    Node *cycle;
    s.detectloop(head, m, cycle);
    cout << cycle->data << endl;
    // cycle->next = NULL;                     // to remove the loop we do this

    Node *slow = head;
    Node *fast = head;
    s.floydCycleDetection(head, slow, fast);

    s.beginningNodeOfLoop(head, slow, fast);
    return 0;
}