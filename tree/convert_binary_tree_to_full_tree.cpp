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

  int binarytofull(Node *root, Node *parent, int left, int right){
    if(root == NULL){
      return 0;
    }
    if(root->left == NULL && root->right == NULL){
      return 1;
    }
    int l = binarytofull(root->left, root, 1, 0);
    int r = binarytofull(root->right, root, 0, 1);
    if(l + r == 1 && parent != NULL){
      if(l == 1){
        if(left == 1){
          parent->left = root->left;
        }
        else if(right == 1){
          parent->right = root->left;
        }
      }
      else{
        if(left == 1){
          parent->left = root->right;
        }
        else if(right == 1){
          parent->right = root->right;
        }
      }
    }
    return 1;

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

  t.binarytofull(root, NULL, 0, 0);
  t.postorder(root);

  cout << endl;
}