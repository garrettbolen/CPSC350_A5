#include "BST.h"

template <typename type> BST<type>::BST(){
  root = NULL;
}

template <typename type> BST<type>::~BST(){
}

template <typename type> void BST<type>::printTree(TreeNode<type>* node){
  if(node == NULL)
    return;
  printTree(node->left);
  cout << node->key << endl;
  printTree(node->right);
}

template <typename type> void BST<type>::copyTree(TreeNode<type>* node){
  if(node == NULL)
    return;
  copyTree(node->left);
  insert(node->key, node->data);
  copyTree(node->right);
}

template <typename type> TreeNode<type>* BST<type>::getMax(){
  TreeNode<type>* curr = root;

  if(root == NULL)
    return NULL;

  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;
}

template <typename type> bool BST<type>::isEmpty(){
  return(root == NULL);
}

template <typename type> void BST<type>::insert(int k, type value){

  if(search(k)){
    cout << "Value already exists." << endl;
    return;
  }
  TreeNode<type>* node = new TreeNode<type>(k, value);

  if(isEmpty()){
    //empty Tree
    root = node;
  }
  else{
    //not an empty Tree
    TreeNode<type>* curr = root;
    TreeNode<type>* parent;

    while(true){
      parent = curr;
      if(k < curr->key){
        //go left
        curr = curr->left;
        if(curr == NULL){
          parent->left = node;
          break;
        }
      }
      else{
        //go right
        curr = curr->right;
        if(curr == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <typename type> bool BST<type>::search(int k){
  if(isEmpty())
    return false;
  else{
    //not an empty Tree
    TreeNode<type>* curr = root;

    while(curr->key != k){
      if(k < curr->key)
        curr = curr->left;
      else
        curr = curr->right;
      if(curr == NULL)
        return false; //didn't find value
    }
  }
  return true; //found value
}

template <typename type> bool BST<type>::deleteNode(int k){
  if(isEmpty())
    return false;

  TreeNode<type>* parent = root;
  TreeNode<type>* curr = root;
  bool isLeft = true;

  while(curr->key != k){
    parent = curr;
    if(k < curr->key){
      isLeft = true;
      curr = curr->left;
    }else{
      isLeft = false;
      curr = curr->right;
    }
    if(curr == NULL)
      return false;
  }
  //if we make it here, value found and time to delete
  if(curr->left == NULL && curr->right == NULL){
    //leaf node
    if(curr == root)
      root = NULL;
    else if(isLeft)
      parent->left = NULL;
    else
      parent->right = NULL;
  }
  else if(curr->right == NULL){ //no right child, so must have left child
    if(curr == root)
      root = curr->left = curr->left;
    else if(isLeft)
      parent->left = curr->left;
    else
      parent->right = curr->left;
  }
  else if(curr->left == NULL){ //no right child, so must have left child
    //these branching statements identify position of node to be deleted
    if(curr == root)
      root = curr->left = curr->right;
    else if(isLeft)
      parent->left = curr->right;
    else
      parent->right = curr->right;
  }
  else{
    //node to be deleted has two children
    TreeNode<type>* successor = getSuccessor(curr);

    if(curr == root)
      root = successor;
    else if(isLeft)
      parent->left = successor;
    else
      parent->right = successor;

    //connect successor to current's left child
    successor->left = curr->left;
    return true;
  }
}

template <typename type> TreeNode<type>* BST<type>::getSuccessor(TreeNode<type>* d){
  //parameter d represents the node to be deleted
  TreeNode<type>* curr = d->right;
  TreeNode<type>* sp = d;
  TreeNode<type>* successor = d;

  while(curr != NULL){
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template class BST<Student>;
template class BST<Faculty>;
