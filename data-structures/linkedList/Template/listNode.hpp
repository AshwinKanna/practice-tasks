
#ifndef LISTNODE_HPP
#define LISTNODE_HPP

template < class nodeType>
class linkedList;

template < class nodeType >
class node {
    friend class linkedList<nodeType>;
    public:
        node(const nodeType &);
        nodeType getValue() const;
    private:
        nodeType value;
        node<nodeType> *nextPtr;
};

template < class nodeType >
node<nodeType>::node(const nodeType &val) : value(val), nextPtr(nullptr) {}

template < class nodeType >
nodeType node<nodeType>::getValue() const {
    return value;
}

#endif