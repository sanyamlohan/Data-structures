#include<iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node * left;
    Node *right;

    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class tree{
    public:
    void preorder(Node *root){
        if(root == NULL){
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void modifiedPreorder(Node *root1, Node *root2, int &check){
        if(root1 == NULL && root2 != NULL){
            check = 0;
            return;
        }
        else if(root1 != NULL && root2 == NULL){
            check = 0;
            return;
        }
        if(root1 == NULL && root2 == NULL){
            return;
        }
        if(root1->data == root2->data){
            modifiedPreorder(root1->left, root2->left, check);
            modifiedPreorder(root1->right, root2->right, check);
        }
        else{
            check = 0;
            return;
        }
    }

    void checksubtree(Node *root1, Node *root2, int &check){
        if(check == 0){
            return;
        }
        if(root1 == NULL){
            return;
        }
        if(root1->data == root2->data){
            modifiedPreorder(root1, root2, check);
        }
        checksubtree(root1->left, root2, check);
        checksubtree(root1->right, root2, check);
    }
};

int main(){
    Node *root1 = new Node(1);
    Node *t1 = new Node(2);
    Node *t2 = new Node(3);
    Node *t3 = new Node(4);
    Node *t4 = new Node(5);
    Node *t5 = new Node(6);
    Node *t6 = new Node(7);

    root1->left = t1;
    root1->right = t2;
    t1->left = t3;
    t1->right = t4;
    t3->right = t6;
    t2->right = t5;

    Node *root2 = new Node(2);
    Node *p1 = new Node(4);
    Node *p2 = new Node(5);
    Node *p3 = new Node(7);

    root2->left = p1;
    root2->right = p2;
    p1->right = p3;

    tree t;
    t.preorder(root1);
    cout << endl;

    t.preorder(root2);
    cout << endl;

    int check = 1;
    t.checksubtree(root1, root2, check);
    if(check != 0){
        cout << "subtree" << endl;
    }
    else{
        cout << "not subtree" << endl;
    }


    return 0;
}