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

  int maxsum(Node *root){
    if(root == NULL){
      return 0;
    }

    int l = maxsum(root->left);
    int r = maxsum(root->right);

    return max(l, r) + root->data;
  }

  void printpath(Node *root, vector<int> v, int sum){
    if(root == NULL){
      return;
    }
    sum = sum - root->data;
    v.push_back(root->data);
    if(sum == 0 && root->left == NULL && root->right == NULL){
      for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
      }
    }
    printpath(root->left, v, sum);
    printpath(root->right, v, sum);
  }
};

int main(){
  Node *root = new Node(1);
  Node *t1 = new Node(2);
  Node *t2 = new Node(3);
  Node *t3 = new Node(8);
  Node *t4 = new Node(4);
  Node *t5 = new Node(5);
  Node *t6 = new Node(6);
  Node *t7 = new Node(10);
  Node *t8 = new Node(7);
  Node *t9 = new Node(9);
  Node *t10 = new Node(5);

  root->left = t1;
  root->right = t2;
  t1->left = t3;
  t1->right = t4;
  t4->left = t7;
  t2->left = t5;
  t2->right = t6;
  t5->left = t8;
  t5->right = t9;
  t6->right = t10;

  tree t;
  t.postorder(root);
  cout << endl;

  int ans = t.maxsum(root);
  cout << ans << endl;

  vector<int> v;
  t.printpath(root, v, ans);
  cout << endl;
}