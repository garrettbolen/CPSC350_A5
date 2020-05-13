#include "Menu.h"
using namespace std;

Menu::Menu(){
  masterFaculty = new BST<Faculty>();
  masterStudent = new BST<Student>();
  history = new Rollback(masterStudent, masterFaculty);
  running = true;
}

Menu::~Menu(){

}

void Menu::run(){
  displayMenu();

  cin >> choice;

  //else if statements for choice
  if(choice == 1){
    masterStudent->printTree(masterStudent->root);
  } else if(choice == 2){
    masterFaculty->printTree(masterFaculty->root);
  } else if(choice == 3){
    cout << "Enter the student ID: ";
    cin >> someID;
    masterStudent->get(someID)->data.printInfo();
  } else if (choice == 4){
    cout << "Enter the faculty ID: ";
    cin >> someID;
    masterFaculty->get(someID)->data.printInfo();
  } else if(choice == 5){
    cout << "Enter the student ID: ";
    cin >> someID;
    int fid = masterStudent->get(someID)->data.advisorID;
    masterFaculty->get(fid)->data.printInfo();
  } else if(choice == 6){
    cout << "Enter the faculty ID: ";
    cin >> someID;
    ListNode<int>* curr = masterFaculty->get(someID)->data.students->front;
    while(curr != NULL){
      masterStudent->get(curr->data)->data.printInfo();
      cout << endl;
      curr = curr->next;
    }
  }else if(choice == 8){
    cout << "To delete a student, enter the student's ID: ";
    cin >> someID;
    masterStudent->deleteNode(someID);
  } else if(choice == 10){
    cout << "To delete a faculty member, enter their ID: ";
    cin >> someID;
    masterFaculty->deleteNode(someID);
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
