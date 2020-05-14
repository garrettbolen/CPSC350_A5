#include "ListNode.h"
#pragma once

template <typename type> class DoublyLinkedList{
  public:
    DoublyLinkedList();

    void insertFront(type data);
    void insertBack(type d);
    type removeFront();

    // int search(type val);
    // type removeAtPos(int pos);
    type remove(type val);
    type peek();

    unsigned int getSize();
    bool isEmpty();

    ListNode<type>* front;
    ListNode<type>* back;
    unsigned int size;
    void printList();
};
