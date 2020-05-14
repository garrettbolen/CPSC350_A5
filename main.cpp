#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include "GenStack.h"
#include "Menu.h"

int main(int argc, char const *argv[]) {
  Menu menu;
  while(menu.running){
    menu.run();
  }
  return 0;
}
