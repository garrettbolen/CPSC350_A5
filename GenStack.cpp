#include "GenStack.h"

template<class T>
GenStack<T>::GenStack(){
  myArray = new T[10];
  maxSize = 10;
  top = -1;
}

template<class T>
GenStack<T>::GenStack(int mSize){
  myArray = new T[mSize];
  maxSize = mSize;
  top = -1;
}

template<class T>
GenStack<T>::~GenStack(){
  clearArray();
}

template<class T>
void GenStack<T>::clearArray(){
  delete []myArray;
}

template<class T>
void GenStack<T>::push(T data){
  if(!isFull()){
    myArray[++top] = data;
  } else {
    maxSize *= 2;
    T* temp = new T[maxSize];

    for(int i = 0; i < (maxSize/2); ++i){
      temp[i] = myArray[i];
    }
    clearArray();

    myArray = new T[maxSize];
    for(int i = 0; i < (maxSize/2); ++i){
      myArray[i] = temp[i];
    }
    delete []temp;
    myArray[++top] = data;
  }
}

template<class T>
T GenStack<T>::pop(){
  if(!isEmpty()){
    return myArray[top--];
  } else {
    cout << "Stack empty." << endl;
  }
  T null;
  return null;
}

template<class T>
T GenStack<T>::peek(){
  return myArray[top];
}

template<class T>
bool GenStack<T>::isEmpty(){
  return(top == -1);
}

template<class T>
bool GenStack<T>::isFull(){
  return(top == (maxSize-1));
}

template class GenStack<Transaction>;
