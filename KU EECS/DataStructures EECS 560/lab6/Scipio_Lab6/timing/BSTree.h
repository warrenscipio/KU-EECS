#ifndef BSTREE_H
#define BSTREE_H

class BSTree {
    
    BSTree * left;
    BSTree * right;
    int value;

    public:
       
        BSTree();
        BSTree(int value);
        BSTree(BSTree * l, BSTree * r);

        ~BSTree();

        void setLeft(BSTree * l);
        void setRight(BSTree * l);

        BSTree * getLeft();
        BSTree * getRight();

        bool hasNullPointers();
        int getValue();
};

#endif
