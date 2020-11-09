#ifndef _bst_hpp
#define _bst_hpp

#include <iostream>

// BST Node
using namespace std;

class Node {
  public:
  string str;
  int count;
  int key;
  Node* left;
  Node* right;

  // Default Constructor
  Node() {
    str = "";
    key = 0;
    left = NULL;
    right = NULL;
  }

  // Parametrized Constructor
  Node(string str_, int val) {
    str = str_;
    key = val;
    left = NULL;
    right = NULL;
  }
};

// BST Class
class BinarySearchTree {

private:
    Node * root;

public:
    BinarySearchTree(string rootString, int rootValue) {
        root=new Node(rootString, rootValue);
    }
    
    Node* getRoot() {
        return root;
    }

    void invert(Node* node) 
    { 
        if (node == NULL) 
            return; 
        else
        { 
            struct Node* temp; 
            
            /* recursive calls */
            invert(node->left); 
            invert(node->right); 
        
            /* swap the pointers in this node */
            temp = node->left; 
            node->left = node->right; 
            node->right = temp; 
        } 
    }

    void inorder(Node *root) { 
        if (root != NULL) { 
            inorder(root->left); 
            cout << root->str << ": " << root->key << endl; 
            inorder(root->right); 
        } 
    } 

    Node* insert(Node* node, string str, int key) { 
        if (node == NULL) return new Node(str, key); 
        if (key < node->key) 
            node->left  = insert(node->left, str, key); 
        else if (key > node->key) 
            node->right = insert(node->right, str, key);
        return node; 
    } 
};

#endif