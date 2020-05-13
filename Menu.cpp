#include "Menu.h"
using namespace std;

Menu::Menu(){
  masterFaculty = new BST<Faculty>();
  masterStudent = new BST<Student>();
  history = new Rollback;
  running = true;
}

Menu::~Menu(){

}

void Menu::run(){
  displayMenu();

  cin >> choice;

  //else if statements for choice
  if(choice == 1){
    masterStudent->printTree();
  } else if(choice == 2){
    masterFaculty->printTree(masterFaculty->getRoot());
  } else if(choice == 3 || choice == 5){
    cout << "Enter the student ID: ";
    cin >> someID;
    masterStudent->search(someID, choice);
  } else if (choice == 4 || choice == 6){
    cout << "Enter the faculty ID: ";
    cin >> someID;
    masterFaculty->search(someID, choice);
  } else if(choice == 14){
    running = false;
  }
}

void Menu::displayMenu(){
  cout << "Student and Faculty Records Database: " << endl;
  cout << "1. Print all students and their information." << endl;
  cout << "2. Print all faculty and their information." << endl;
  cout << "3. Find and display student information (using ID)." << endl;
  cout << "4. Find and display faculty information (using ID)." << endl;
  cout << "5. Find a student's faculty advisor (using ID)." << endl;
  cout << "6. Print faculty's advisees (using ID)." << endl;
  cout << "7. Add new student." << endl;
  cout << "8. Delete a student." << endl;
  cout << "9. Add new faculty member." << endl;
  cout << "10. Delete a faculty member." << endl;
  cout << "11. Change student advisor." << endl;
  cout << "12. Remove advisee from faculty member." << endl;
  cout << "13. Rollback." << endl;
  cout << "14. Exit." << endl;
}
