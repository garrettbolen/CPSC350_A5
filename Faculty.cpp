#include "Faculty.h"

Faculty::Faculty(){

}

Faculty::Faculty(string n, int id, string l, string d){
  idNum = id;
  name = n;
  level = l;
  department = d;
  students = new DoublyLinkedList<int>();
  numAdvisees = 0;
}
Faculty::~Faculty(){
  //deconstructor
  //delete
}


void Faculty::printInfo(){
  cout << "Faculty Name: " << name << ", ID: " << idNum << ", Level: " << level << ", Deparment: " << department << ", Advisees: ";
  students->printList();
  cout << endl;
}
