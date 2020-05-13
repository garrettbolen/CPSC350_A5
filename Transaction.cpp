#include "Transaction.h"

Transaction::Transaction(){

}

Transaction::Transaction(string s, string p, BST<Student>* tree){
  type = s;
  person = p;
  studTree = new BST<Student>();
  studTree->copyTree(tree->root);
}

Transaction::Transaction(string s, string p, BST<Faculty>* tree){
  type = s;
  person = p;
  facTree = new BST<Faculty>();
  facTree->copyTree(tree->root);
}

Transaction::Transaction(string s, string p, int sid, int fid){
  type = s;
  person = p;
  studID = sid;
  facID = fid;
}

Transaction::~Transaction(){

}
