#include <iostream>
#include "Student.h"
#include "Faculty.h"
using namespace std;
#pragma once

template <typename type> class TreeNode{
public:
  TreeNode();
  TreeNode(int k, type o);
  ~TreeNode();

  int key;
  type data;
  TreeNode<type>* left;
  TreeNode<type>* right;
};
