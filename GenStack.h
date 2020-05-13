#include <iostream>
#include "Transaction.h"
using namespace std;

#pragma once

template<class T>
class GenStack{
public:
  GenStack<T>();
  GenStack<T>(int mSize);
  ~GenStack();

  void push(T data);
  T pop();
  T peek();

  bool isFull();
  bool isEmpty();

private:
  int top = -1;
  int maxSize = 0;

  T *myArray;
  void clearArray();
};
