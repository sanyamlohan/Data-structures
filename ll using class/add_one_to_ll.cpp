#include<iostream>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};

int add( LinkedListNode<int> *current){
    if(current->next == NULL){
        current->data = current->data + 1;
        if(current->data > 9){
            current->data = 0;
            return 1;
        }
        else{
            return 0;
        }
    }
    int carry = add(current->next);
    if(carry == 1){
        current->data = current->data + 1;
        if(current->data > 9){
            current->data = 0;
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
    
}
LinkedListNode<int>* addOneToList(LinkedListNode<int> *head)
{
    int a = add(head);
    if(a == 0){

        return head;
    }
    else{
        LinkedListNode<int>* x = new LinkedListNode<int>(1);
        x->next = head;
        head = x;
        return head;
    }
    
}

void insertAtTail(LinkedListNode<int> *&head){
    int data;
    cout << "enter data which you want to insert at end: ";
    cin >> data;
    LinkedListNode<int> *temp = new LinkedListNode<int>(data);
    
    LinkedListNode<int> *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void printLinkedList(LinkedListNode<int> *&head){
    LinkedListNode<int> *ptr = head;
    while(ptr!=NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main(){
    int num;
    cout << "enter how many nodes you want to insert in linked list: ";
    cin >> num;

    int data;
    cout << "enter data of first node: ";
    cin >> data;
    LinkedListNode<int> *head = new LinkedListNode<int>(data);

    for(int i=0; i<num-1; i++){
        insertAtTail(head);
    }

    printLinkedList(head);

    LinkedListNode<int> *newhead = addOneToList(head);
    printLinkedList(newhead);

}