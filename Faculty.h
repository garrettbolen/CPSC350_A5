#include "Person.h"
#include "DoublyLinkedList.h"

#pragma once

class Faculty : Person{
public:
  Faculty();
  Faculty(string n, int id, string l, string d);
  ~Faculty();

  void printInfo();
  void printAdvisees();

  void addAdvisee(int idNum);
  void removeAdvisee(int idNum);

  int numAdvisees;
  string department;
  DoublyLinkedList<int>* students;

  string getDepartment();
  int getNumAdvisees();
};
