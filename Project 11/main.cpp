#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node* parent;
};

    Node* FindMin(Node *n){
        if(n == NULL){
            return NULL;
        }
        if(n->left)
            return FindMin(n -> left);
        else
            return n;
    }

    Node* FindMax(Node* n){
        if(n == NULL){
            return NULL;
        }
        if(n->right){
            return(FindMax(n->right));
        }
        else
            return n;
    }

    Node* Insert(Node* n, int key){
        if(n == NULL){
            Node* temp;
            temp = new Node;
            temp ->data = key;
            temp -> left = temp ->right = NULL;
            return temp;
        }
        if(key >(n -> data)){
            n->right = Insert(n->right,key);
        }
        else if(key < (n ->data)){
            n -> left = Insert(n->left,key);
        }
    }

    Node* Delete(Node *n, int key){
       Node *temp;
       if(n== NULL){
        cout << "Element Not Found";
       }
       else if(key < n -> data){
            n-> left = Delete(n->left,key);
       }
       else if(key > n ->data){
            n->right =Delete(n->right,key);
       }
       else{
            if(n-> right&& n ->left){
                temp = FindMin(n->right);
                n -> data = temp ->data;
                n->right = Delete(n-> right, temp ->data);
            }
            else{
                temp = n;
                if(n ->left == NULL){
                    n= n->right;
                }
                else if(n-> right ==NULL){
                    n =n->left;
                }
                free(temp);

            }
       }
}

    void preorder(Node *n){
        if(n == NULL){
            return;
        }
        cout<<n->data<<endl;
        preorder(n->left);
        preorder(n->right);
    }

    void inorder(Node *n){
        if(n == NULL){
            return;
        }
        inorder(n->left);
        cout<<n->data<<endl;
        inorder(n->right);

    }

    void postorder(Node *n){
        if(n ==NULL){
            return;
        }
        postorder(n -> left);
        postorder(n -> right);
        cout<<n->data<<endl;
    }

int main() {
 Node *root = NULL, *temp;
  string s;

  getline(cin, s);

  while(true){

    if(s[0] == 'e'){
      break;
    } else if(s.substr(0,3) == "pre"){
      preorder(root);
      cout<<"++++++++++++";
       } else if(s.substr(0,2) == "in"){
      inorder(root);
      cout<<"++++++++++++";
    } else if(s.substr(0,4) == "post"){
      postorder(root);
      cout<<"++++++++++++";
    } else if(s[0] == 'i'){
      int key = stoi(s.substr(2,s.length()-2));
      root = Insert(root, key);
    } else if(s[0] == 'd'){
      int key = stoi(s.substr(2,s.length()-2));
      root=Delete(root, key);
    }

    getline(cin, s);

  }

  return 0;
}

