#include "Transaction.h"

Transaction::Transaction(){

}

Transaction::Transaction(string s, BST<Student>* tree){
  type = s;
  studTree = new BST<Student>();
  studTree->copyTree(tree->root);
}

Transaction::Transaction(string s, BST<Faculty>* tree){
  type = s;
  facTree = new BST<Faculty>();
  facTree->copyTree(tree->root);
}

Transaction::Transaction(string s, int id){
  type = s;
  oldID = id;
}

Transaction::~Transaction(){
  
}
