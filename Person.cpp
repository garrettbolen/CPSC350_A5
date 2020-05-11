#include "Person.h"
using namespace std;

Person::Person(){
  //default
}

Person::~Person(){
  //deconstructor
}
int Person::getID(){
  return idNum;
}
void Person::setID(int idNum){
  idNum = idNum;
}

string Person::getName(){
  return name;
}

string Person::getLevel(){
  return level;
}
