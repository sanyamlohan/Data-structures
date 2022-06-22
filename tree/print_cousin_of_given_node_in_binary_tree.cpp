#include<iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node *left;
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

    int levelParent(Node *root, int l, int num, int &level_num, int &parent_num){
        if(root == NULL){
            return 0;
        }
        if(root->data == num){
            level_num = l;
            return 1;
        }
        int res = 0, res1 = 0;
        res = levelParent(root->left, l+1, num, level_num, parent_num);
        res1 = levelParent(root->right, l+1, num, level_num, parent_num);
        if(res == 1 || res1 ==1){
            parent_num = root->data;
            return 0;
        }
        return 0;
    }

    void printCousins(Node *root, int parent_num, int level_num, int level){
        if(root == NULL){
            return;
        }
        if(root->data == parent_num){
            return;
        }
        if(level_num == level){
            cout << root->data << " ";
        }
        printCousins(root->left, parent_num, level_num, level+1);
        printCousins(root->right, parent_num, level_num, level+1);
    }
};

int main(){
    Node *root = new Node(1);
    Node *p1 = new Node(2);
    Node *p2 = new Node(3);
    Node *p3 = new Node(4);
    Node *p4 = new Node(5);
    Node *p5 = new Node(6);
    Node *p6 = new Node(7);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    tree t;
    cout << "preorder: ";
    t.preorder(root);
    cout << endl;

    int num;
    cout << "enter the number of which you need to find the cousins: ";
    cin >> num;

    int level_num = 0;
    int parent_num = -1;
    t.levelParent(root, 0, num, level_num, parent_num);
    cout << "level_num: " << level_num << endl;
    cout << "parent_num: " << parent_num << endl;
    cout << endl;

    cout << "cousins of " << num << " are: ";
    t.printCousins(root, parent_num, level_num, 0);
    cout << endl;
}