#include "Rollback.h"

Rollback::Rollback(){

}

Rollback::Rollback(BST<Student>*& stud, BST<Faculty>*& fac){
  studMaster = stud;
  facMaster = fac;
  stack = new GenStack<Transaction>();
}

Rollback::~Rollback(){

}

void Rollback::undo(){
  if(stack->isEmpty()){
    cout << "Nothing to undo." << endl;
    return;
  }
  Transaction tran = stack->pop();
  if(tran.type == "add" || tran.type == "delete"){
    undoAddDelete(tran);
  }
  else if(tran.type == "change"){
    undoChange(tran);
  }
  else{
    cout << "Nothing to undo." << endl;
    return;
  }
}

void Rollback::undoAddDelete(Transaction tran){
  if(tran.person == "student"){
    studMaster = tran.studTree;
  }
  else if(tran.person == "faculty"){
    facMaster = tran.facTree;
  }
  else{
    cout << "Could not undo." << endl;
  }
}

void Rollback::undoChange(Transaction tran){
  if(tran.person == "student"){
    studMaster->get(tran.studID)->data.advisorID = tran.facID;
  }
  else if(tran.person == "faculty"){
    facMaster->get(tran.facID)->data.students->insertBack(tran.studID);
  }
  else{
    cout << "Could not undo." << endl;
  }
}

void Rollback::addTransaction(Transaction tran){
  stack->push(tran);
}
