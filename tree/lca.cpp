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

  int lca(Node *root, int a, int b, int &ans){
    int x = 0;
    if(root == NULL){
      return 0;
    }
    if(root->data == a  || root->data == b){
      x = 1;
    }
    int l = lca(root->left, a, b, ans);
    int r = lca(root->right, a, b, ans);
    int sum = 0;
    sum = x + l + r;
    if(sum == 2){
      ans = root->data;
      sum = -1;
    }
    return sum;
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
  t1->right = t3;
  t2->left = t4;
  t2->right = t5;
  t4->left = t6;
  t4->right = t7;

  tree t;
  t.postorder(root);
  cout << endl;

  int a,b;
  cout << "enter a and b: ";
  cin >> a >> b;

  int ans = -1;
  t.lca(root, a, b, ans);
  if(ans == -1){
    cout << "NO LCA" << endl;
  }
  else{
    cout << ans << endl;
  }
}