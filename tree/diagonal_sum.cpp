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
  
  void diagonalsum(Node *root, int diagonal, map<int, int> &v){
    if(root == NULL){
      return;
    }

    v[diagonal] = v[diagonal] + root->data;
    
    diagonalsum(root->left, diagonal+1, v);
    diagonalsum(root->right, diagonal, v);
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

  root->left = t1;
  root->right = t2;
  t1->left = t3;
  t2->left = t4;
  t2->right = t5;
  t4->left = t6;
  t4->right = t7;

  tree t;
  t.postorder(root);
  cout << endl;

  int diagonal = 0;
  map <int, int> v;
  t.diagonalsum(root, diagonal, v);

  for(int i=0; i<v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}