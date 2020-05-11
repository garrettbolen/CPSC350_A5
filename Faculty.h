#include "Person.h"
//#include " "
#include<iostream>

class Faculty : Person{
  Faculty();
  Faculty(string n, int id, string l, string d);
  ~Faculty();

  void printFaculty();
  void printAdvisees();

  void addAdvisee(int idNum);
  void removeAdvisee(int idNum);

  int numAdvisees;
  string department;

  string getDepartment();
  int getNumAdvisees();
};
