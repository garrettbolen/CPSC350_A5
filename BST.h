#include "TreeNode.h"
#pragma once

template <typename type> class BST{
public:
  BST();
  ~BST();

  void insert(int k, type value);
  bool search(int k);
  bool deleteNode(int k);

  bool isEmpty();
  TreeNode<type>* getMin();
  TreeNode<type>* getMax();

  TreeNode<type>* getSuccessor(TreeNode<type>* d);
  void printTree(TreeNode<type>* node);
private:
  TreeNode<type>* root;
};
