#include "Faculty.h"
using namespace std;

Faculty::Faculty(){

}

Faculty::Faculty(string n, int id, string l, string d){
  idNum = id;
  name = n;
  level = l;
  department = d;

  numAdvisees = 0;
}
Faculty::~Faculty(){
  //deconstructor
  //delete
}


void Faculty::printFaculty(){
  cout << "Faculty Name: " << name << ", ID: " << idNum << ", Level: " << level << ", Deparment: " << department << "." << endl;
  // print advisees
}

// void Faculty::printAdvisees(){
//   if(numAdvisees = 0){
//     cout << "Advisor has no advisees." << endl;
//   } else {
//     for(int i = 0; i < maxArraySize; ++i){
//       //if
//     }
//   }
// }
