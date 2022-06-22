#include<iostream>
#include<vector>
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
  
  void postorder(Node *root){
    if(root == NULL){
      return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }

  int printancestors(Node *root, int a, int x){
    int l = 0, r = 0;
    if(root == NULL){
      return 0;
    }
    if(root->data == a){
      return 1;
    }
    l = printancestors(root->left, a, x);
    r = printancestors(root->right, a, x);
    
    if(root->data != a && l+r == 1){
      cout << root->data << " ";
      return l+r;
    }
    else if(root->data == x && l+r == 1){
      cout << root->data << " ";
      return 0;
    }
    return l + r;
  }
  
};

int main(){
  Node *root = new Node(1);
  Node *t1 = new Node(2);
  Node *t2 = new Node(3);
  Node *t3 = new Node(4);
  Node *t4 = new Node(5);
  Node *t5 = new Node(6);
  Node *t6 = new Node(7);
  Node *t7 = new Node(8);
  Node *t8 = new Node(9);

  root->left = t1;
  root->right = t2;
  t1->left = t3;
  t1->right = t4;
  t2->left = t5;
  t2->right = t6;
  t5->left = t7;
  t6->right = t8;

  tree t;
  t.postorder(root);
  cout << endl;

  int a;
  cout << "enter no.: ";
  cin >> a;
  t.printancestors(root, a, 1);
  cout << endl;
}