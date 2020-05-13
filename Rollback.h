#include "Transaction.h"
#include "GenStack.h"

#pragma once

class Rollback{
public:
  Rollback();
  Rollback(BST<Student>*& stud, BST<Faculty>*& fac);
  ~Rollback();

  GenStack<Transaction>* stack;
  BST<Student>* studMaster;
  BST<Faculty>* facMaster;

  void undo();
  void undoAddDelete(Transaction tran);
  void undoChange(Transaction tran);
  void addTransaction(Transaction tran);
  
};
