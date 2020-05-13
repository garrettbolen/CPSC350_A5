#include "BST.h"

#pragma once

class Transaction{
public:
  Transaction();
  Transaction(string s, BST<Student>* tree);
  Transaction(string s, BST<Faculty>* tree);
  Transaction(string s, int id);
  ~Transaction();
  string type;
  BST<Student>* studTree;
  BST<Faculty>* facTree;
  int oldID;
};
