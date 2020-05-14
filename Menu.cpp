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
    if(masterStudent->search(someID))
      masterStudent->get(someID)->data.printInfo();
    else
      cout << "Student record not found." << endl;

  } else if (choice == 4){
    cout << "Enter the faculty ID: ";
    cin >> someID;
    if(masterFaculty->search(someID))
      masterFaculty->get(someID)->data.printInfo();
    else
      cout << "Faculty record not found." << endl;

  } else if(choice == 5){
    cout << "Enter the student ID: ";
    cin >> someID;
    if(masterStudent->search(someID)){
      int fid = masterStudent->get(someID)->data.advisorID;
      if(fid == -1)
        cout << "No advisor assigned." << endl;
      else
        masterFaculty->get(fid)->data.printInfo();
    }
    else
      cout << "Student record not found." << endl;

  } else if(choice == 6){
    cout << "Enter the faculty ID: ";
    cin >> someID;
    if(masterFaculty->search(someID)){
      ListNode<int>* curr = masterFaculty->get(someID)->data.students->front;
      while(curr != NULL){
        masterStudent->get(curr->data)->data.printInfo();
        cout << endl;
        curr = curr->next;
      }
    }
    else
      cout << "Faculty record not found." << endl;

  } else if(choice == 7){
    Transaction t("add", "student", masterStudent);
    history->addTransaction(t);

    string name = "", level = "", major = "";
    int id = 0, advisor = 0;
    double gpa = 0.0;

    cout << "Enter the name of the student: ";
    cin >> name;
    cout << "Enter the ID number of the student: ";
    cin >> id;
    cout << "Enter the level of the student: ";
    cin >> level;
    cout << "Enter the major of the student: ";
    cin >> major;
    cout << "Enter the GPA of the student: ";
    cin >> gpa;
    cout << "Enter the student's advisor's ID number: ";
    cin >> advisor;

    if(!masterFaculty->search(advisor))
      advisor = -1;

    Student s(name, id, level, major, gpa, advisor);
    masterStudent->insert(id, s);

  } else if(choice == 8){
    Transaction t("delete", "student", masterStudent);
    history->addTransaction(t);

    cout << "To delete a student, enter the student's ID: ";
    cin >> someID;
    if(masterStudent->search(someID))
      masterStudent->deleteNode(someID);
    else
      cout << "Student record not found." << endl;

  } else if(choice == 9){
    Transaction t("add", "faculty", masterFaculty);
    history->addTransaction(t);

    string name = "", level = "", department = "";
    int id = 0;

    cout << "Enter the name of the faculty member: ";
    cin >> name;
    cout << "Enter the ID number of the faculty member: ";
    cin >> id;
    cout << "Enter the level of the faculty member: ";
    cin >> level;
    cout << "Enter the department of the faculty member: ";
    cin >> department;

    Faculty f(name, id, level, department);
    masterFaculty->insert(id, f);

  } else if(choice == 10){
    Transaction t("delete", "faculty", masterFaculty);
    history->addTransaction(t);

    cout << "To delete a faculty member, enter their ID: ";
    cin >> someID;
    if(masterFaculty->search(someID))
      masterFaculty->deleteNode(someID);
    else
      cout << "Faculty record not found." << endl;

  } else if(choice == 11){
    int newID = 0;

    cout << "To change a student's advisor, enter the student's ID: ";
    cin >> someID;
    if(masterStudent->search(someID)){
      Transaction t("change", "student", someID, masterStudent->get(someID)->data.advisorID);
      history->addTransaction(t);

      cout << "Enter the ID of the new advisor: ";
      cin >> newID;
      if(masterFaculty->search(newID))
        masterStudent->get(someID)->data.advisorID = newID;
      else
        cout << "Advisor not found." << endl;
    }
    else
      cout << "Student record not found." << endl;

  } else if(choice == 12){
    int removeID = 0;

    cout << "To remove an advisee, enter the faculty's ID: ";
    cin >> someID;
    if(masterFaculty->search(someID)){
      cout << "Enter the ID of the new advisor: ";
      cin >> removeID;
      if(masterStudent->search(removeID)){
        Transaction t("change", "faculty", removeID, someID);
        history->addTransaction(t);

        masterFaculty->get(someID)->data.students->remove(removeID);
      }
      else
        cout << "Advisee not found." << endl;
    }
    else
      cout << "Faculty record not found." << endl;

  } else if(choice == 13){
    history->undo();
    cout << "Rolled back." << endl;

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
