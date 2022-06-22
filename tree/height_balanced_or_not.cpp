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

  int heightbalanced(Node *root, int &ans){
    if(root == NULL){
      return -1;
    }

    int l = heightbalanced(root->left, ans);
    int r = heightbalanced(root->right, ans);
    int difference = l - r;
    if(difference >= -1 && difference <= 1){
      return max(l, r) + 1;
    }
    else{
      ans = 0;
      return max(l, r) + 1;
    }
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

  root->left = t1;
  root->right = t2;
  t2->left = t3;
  t2->right = t4;
  t3->left = t5;
  t3->right = t6;

  tree t;
  t.postorder(root);
  cout << endl;

  int ans = 1;
  t.heightbalanced(root, ans);
  if(ans == 1){
    cout << "height balanced" << endl;
  }
  else{
    cout << "not height balanced" << endl;
  }
  cout << endl;
}