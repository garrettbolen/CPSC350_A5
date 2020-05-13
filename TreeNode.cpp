#include "TreeNode.h"

template <typename type> TreeNode<type>::TreeNode(){
  key = 0;
  left = NULL;
  right = NULL;
}

template <typename type> TreeNode<type>::TreeNode(int k, type o){
  key = k;
  data = o;
  left = NULL;
  right = NULL;
}

template <typename type> TreeNode<type>::~TreeNode(){

}

template class TreeNode<Student>;
template class TreeNode<Faculty>;
