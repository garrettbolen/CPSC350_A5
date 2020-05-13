#include <iostream>
#include "BST.h"
#include "Transaction.h"
#include "Rollback.h"

using namespace std;

class Menu{
public:
  Menu();
  ~Menu();

  void run();
  void displayMenu();

  bool isRunning();

  BST<Faculty>* masterFaculty;
  BST<Student>* masterStudent;

  int choice;
  int someID;

};
