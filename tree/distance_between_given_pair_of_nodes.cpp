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

  int lca(Node *root, int a, int b, int &ans){
    int x = 0;
    if(root == NULL){
      return 0;
    }

    if(root->data == a || root->data == b){
      x = 1;
    }

    int l = lca(root->left, a, b, ans);
    int r = lca(root->right, a, b, ans);
    int sum = x+l+r;
    if(sum == 2){
      ans = root->data;
      sum = -1;
    }
    return sum;
  }

  void level(Node *root, int x, int &level_x, int l, int y, int &level_y, int z, int &level_z){
    if(root == NULL){
      return;
    }

    if(root->data == x){
      level_x = l;
    }
    else if(root->data == y){
      level_y = l;
    }
    else if(root->data == z){
      level_z = l;
    }

    level(root->left, x, level_x, l + 1, y, level_y, z, level_z);
    level(root->right, x, level_x, l + 1, y, level_y, z, level_z);
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

  int a, b, ans = 0;
  cout << "enter no.: ";
  cin >> a >> b;
  t.lca(root, a, b, ans);
  cout << endl;
  cout << ans << endl;

  int common, node1, node2;
  t.level(root, ans, common, 0, a, node1, b, node2);

  cout << (node1 - common) + (node2 - common) << endl;
}