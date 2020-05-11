#include <iostream>
using namespace std;

class Person{
public:
  Person();
  ~ Person();

  string getName();
  string getLevel();

  int getID();
  void setID(int idNum);

  int idNum;
  string name;
  string level;
};
