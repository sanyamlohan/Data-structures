#include<bits/stdc++.h>
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

};

int main(){
  Node *root = new Node(0);
  Node *t1 = new Node(1);
  Node *t2 = new Node(2);
  Node *t3 = new Node(3);
  Node *t4 = new Node(4);
  Node *t5 = new Node(5);
  Node *t6 = new Node(6);
  Node *t7 = new Node(7);

  root->left = t1;
  root->right = t2;
  t1->left = t3;
  t3->left = t5;
  t2->left = t4;
  t4->left = t6;
  t4->right = t7;



  tree t;
  t.postorder(root);
  cout << endl;

  cout << endl;
}