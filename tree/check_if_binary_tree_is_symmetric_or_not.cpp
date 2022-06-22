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
  
  void postorder(Node *root){
    if(root == NULL){
      return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }

  void checkSymmetric(Node *root, Node *root1, int &check){
    if(root == NULL && root1 == NULL){
      return;
    }
    if(root->left != NULL && root1->right == NULL){
      check = 0;
      return;
    }
    else if(root->left == NULL && root1->right != NULL){
      check = 0;
      return;
    }
    else if(root->right == NULL && root1->left != NULL){
      check = 0;
      return;
    }
    else if(root->right != NULL && root1->left == NULL){
      check = 0;
      return;
    }
    else{
      checkSymmetric(root->left, root1->right, check);
      checkSymmetric(root->right, root1->left, check);
    }
  }
};

int main(){
  Node *root = new Node(1);
  Node *p1 = new Node(2);
  Node *p2 = new Node(3);
  Node *p3 = new Node(4);
  Node *p4 = new Node(5);

  root->left = p1;
  root->right = p2;
  p1->right = p3;
  p2->left = p4;

  tree t;
  t.postorder(root);
  cout << endl;

  int check = 1;
  if(root->left!=NULL && root->right!=NULL){
    t.checkSymmetric(root->left, root->right, check);
  }
  else{
    check = 0;
  }

  if(check==0){
    cout << "not symmetric" << endl;
  }
  else{
    cout << "symmetric" << endl;
  }

  
}