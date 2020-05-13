#include <iostream>
using namespace std;

#pragma once

class Person{
public:
  Person();
  ~ Person();

  string getName();
  string getLevel();

  int getID();
  void setID(int idNum);
protected:
  int idNum;
  string name;
  string level;
};
