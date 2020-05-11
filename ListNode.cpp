#include "ListNode.h"

template<class T>
ListNode<T>::ListNode(){
  data = 0;
  next = NULL;
  prev = NULL;
}

template<class T>
ListNode<T>::ListNode(int d){
  data = d;
  next = NULL;
}

template<class T>
ListNode<T>::~ListNode(){
  if(next != NULL){
    next = NULL;
    prev = NULL;

    delete next;
    delete prev;
  }
}
