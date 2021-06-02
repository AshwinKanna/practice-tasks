#ifndef TREENODE_HPP
#define TREENODE_HPP

namespace treeNode
{
    template < class nodeType >
    class treenode {
        public:
            treenode(const nodeType &);
            treenode(){}
            const nodeType& getTreeNodeValue() const {
                return value;
            }
            treenode<nodeType>*& getTreeNodeLeftPtr() {
                return leftPtr;
            }
            treenode<nodeType>*& getTreeNodeRightPtr() {
                return rightPtr;
            }

        private:
            nodeType value;
            treenode<nodeType> *leftPtr;
            treenode<nodeType> *rightPtr;
    };
}

template <class nodeType>
treeNode::treenode<nodeType>::treenode(const nodeType &inp_value) : value(inp_value), leftPtr(nullptr), rightPtr(nullptr)
{ }

#endif