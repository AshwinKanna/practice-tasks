#ifndef bst_tree_hpp
#define bst_tree_hpp

#include "treeNode.hpp"
#include <iostream>


template < class nodeType >
class bst_tree : public treeNode::treenode<nodeType> {
    public:
        bst_tree() : treeNode::treenode<nodeType>(), rootPtr(nullptr) {}
        void insertNode(const nodeType &);
        void inOrderDisplay();
    private:
        treeNode::treenode<nodeType> *rootPtr;
        void createAndInsertNode(treeNode::treenode<nodeType> **, const nodeType &);
        void inOrderTraverse(treeNode::treenode<nodeType> *);
};

template<class nodeType>
void bst_tree<nodeType>::createAndInsertNode(treeNode::treenode<nodeType> **root, const nodeType &inp_value) {
    if(*root == nullptr) {
        *root = new treeNode::treenode<nodeType>(inp_value);
    } else {
        if((*root)->getTreeNodeValue() > inp_value)
        {
            createAndInsertNode(&((*root)->getTreeNodeLeftPtr()), inp_value);
        }
        else if((*root)->getTreeNodeValue() < inp_value)
        {
            createAndInsertNode(&((*root)->getTreeNodeRightPtr()), inp_value);
        }
        else
        {
            std::cout << "Duplicate element" << std::endl;
        }
    }
}

template<class nodeType>
void bst_tree<nodeType>::insertNode(const nodeType &inp_value) {
    createAndInsertNode(&rootPtr, inp_value);
}

template<class nodeType>
void bst_tree<nodeType>::inOrderTraverse(treeNode::treenode<nodeType> *root) {
    if(root != nullptr) {
        inOrderTraverse(root->getTreeNodeLeftPtr());
        std::cout << "Data : " << root->getTreeNodeValue() << std::endl;
        inOrderTraverse(root->getTreeNodeRightPtr());
    }
}

template<class nodeType>
void bst_tree<nodeType>::inOrderDisplay() {
    inOrderTraverse(rootPtr);
}

#endif