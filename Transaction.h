#include "BST.h"

#pragma once

class Transaction{
public:
  Transaction();
  Transaction(string s, string p, BST<Student>* tree);
  Transaction(string s, string p, BST<Faculty>* tree);
  Transaction(string s, string p, int sid, int fid);
  ~Transaction();

  string type;
  string person;
  BST<Student>* studTree;
  BST<Faculty>* facTree;
  int studID;
  int facID;
};
