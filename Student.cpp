#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(){
 // default
}

//overloaded
Student::Student(string n, int id, string l, string m, double g, int a){
  name = n;
  idNum = id;
  level = l;
  major = m;
  gpa = g;
  advisorID = a;
}

Student::~Student(){
  // deconstructor
}

// advisor
void Student::setAdvisor(int advisorID){
  advisorID = advisorID;
}

int Student::getAdvisor(){
  return advisorID;
}

//print
void Student::printInfo(){
  cout << "Student name: " << name << ", ID: " << idNum << ", level: " << level << ", Major: " << major << ", GPA: " << gpa << ", Advisor ID: ";

  // check if advisor exists
  if(advisorID == -1){
    cout << "No advisor assigned." << endl;
  } else {
    cout << advisorID << endl;
  }
}

// gpa and major
double Student:: getGPA(){
  return gpa;
}

string Student::getMajor(){
  return major;
}
