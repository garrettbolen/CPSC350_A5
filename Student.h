#include "Person.h"

#pragma once

class Student : Person {
public:
  Student(); //default
  Student(string n, int id, string l, string m, double g, int a); //overloaded
  Student(const Student& stud); //copy constructor
  ~Student(); //destructor

  string major;
  double gpa;
  int advisorID;

  string getMajor();
  double getGPA();
  int getAdvisor();

  void setAdvisor(int advisorID);

  void printInfo();
};
