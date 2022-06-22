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

  void check(Node *&root1, Node *&root3, Node *&root4, int &result, int &run){
    if(root1 == NULL && root3 == NULL){
      return;
    }
    else if(root1 == NULL && root3 != NULL){
      if(root4 == NULL){
        Node *temp = root3;
        root3 = root4;
        root4 = temp;  
        return;
      }
      else{
        result = 0;
        return;
      }
    }
    else if(root1 != NULL && root3 == NULL){
      if(root4 != NULL){
        Node *temp = root3;
        root3 = root4;
        root4 = temp;
        check(root1->left, root3->left, root4, result, run);
        check(root1->right, root3->right, root4, result, run);
      }
      else{
        result = 0;
        return;
      }
    }


    if(root1->data == root3->data){
      check(root1->left, root3->left, root4, result, run);
      check(root1->right, root3->right, root4, result, run);
    }
    else{
      if(root1->data == root4->data){
        Node *temp = root3;
        root3 = root4;
        root4 = temp;
        check(root1->left, root3->left, root3->right, result, run);
        check(root1->right, root3->right, root3->left, result, run);
      }
      else{
        result = 0;
        return;
      }
    }
  }

  void run(Node *&root1, Node *&root2, int &result, int &run){
    while(result == 1 && run == 1){
      // cout << root1->data << " " << root2->data << endl;
      if(root1->data == root2->data){
        check(root1->left, root2->left, root2->right, result, run);
        root1 = root1->right;
        root2 = root2->right;
        if(root1 == NULL && root2 == NULL){
          run = 0;
          break;
        }
      }
      else{
        result = 0;
        run = 0;
      }
    }
  }

};

int main(){
    Node *root = new Node(6);
    Node *t1 = new Node(3);
    Node *t2 = new Node(8);
    Node *t3 = new Node(1);
    Node *t4 = new Node(7);
    Node *t5 = new Node(4);
    Node *t6 = new Node(2);
    Node *t7 = new Node(7);
    Node *t8 = new Node(1);
    Node *t9 = new Node(3);

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
    t2->right = t6;
    t5->left = t7;
    t5->right = t8;
    t6->right = t9;



    Node *root1 = new Node(6);
    Node *t01 = new Node(8);
    Node *t02 = new Node(3);
    Node *t03 = new Node(2);
    Node *t04 = new Node(4);
    Node *t05 = new Node(7);
    Node *t06 = new Node(1);
    Node *t07 = new Node(3);
    Node *t08 = new Node(1);
    Node *t09 = new Node(7);

    root1->left = t01;
    root1->right = t02;
    t01->left = t03;
    t01->right = t04;
    t02->left = t05;
    t02->right = t06;
    t03->left = t07;
    t04->left = t08;
    t04->right = t09;

  tree t;
  t.postorder(root);
  cout << endl;

  t.postorder(root1);
  cout << endl;

  int result = 1, run = 1;
  t.run(root, root1, result, run);

  if(result == 1){
    cout << "possible" << endl;
  }
  else{
    cout << "not possible" << endl;
  }

}