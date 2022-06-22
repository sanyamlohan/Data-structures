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

  int checksumtree(Node *root, int &sum, int &result){
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int a = checksumtree(root->left, sum, result);
    int b = checksumtree(root->right, sum, result);
    sum = sum + a + b;
    if(root->data != sum){
        result = 0;
    }
    return sum;
  }

};

int main(){
  Node *root = new Node(44);
  Node *p1 = new Node(9);
  Node *p2 = new Node(13);
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
  t.postorder(root);
  cout << endl;

   int sum = 0, result = 1;
  t.checksumtree(root, sum, result);
  if(result == 1){
    cout << "sum tree" << endl;
  }
  else{
    cout << "sum tree" << endl;
  }

}