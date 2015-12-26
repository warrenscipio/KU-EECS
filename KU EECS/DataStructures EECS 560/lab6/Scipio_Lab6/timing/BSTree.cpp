#include "BSTree.h"


#ifndef NULL
#define NULL 0
#endif


BSTree::BSTree(){
    BSTree(0);
}


BSTree::BSTree(int value){    
    this->value = value;    
    this->left = NULL;
    this->right = NULL;
}



BSTree::BSTree(BSTree * l, BSTree * r){
    setLeft(l);
    setRight(r);
}


BSTree::~BSTree(){
    if(this->left != NULL)
        delete this->left;
    if(this->right != NULL)
        delete this->right;
}


int BSTree::getValue(){
    return this->value;
}


void BSTree::setLeft(BSTree * l){
    this->left = l;
}


void BSTree::setRight(BSTree * r){
    this->right = r;
}



BSTree * BSTree::getLeft(){
    if(this->left == NULL)
        return NULL;
    return this->left;
}



BSTree * BSTree::getRight(){
    if(this->right == NULL)
        return NULL;
    return this->right;
}


bool BSTree::hasNullPointers(){
    if(getLeft() == NULL || getRight() == NULL)
        return true;
    return false;
}
