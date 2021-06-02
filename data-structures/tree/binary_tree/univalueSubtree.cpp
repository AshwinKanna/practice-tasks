// https://www.geeksforgeeks.org/find-count-of-singly-subtrees/

#include <iostream>

using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
// Utility function to create a new node 
Node* newNode(int data) 
{ 
    Node* temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 

bool implementor(Node* root, int& count) {
    if(!root)
        return true;
    
    bool leftSubtree = implementor(root->left, count);
    bool rightSubtree = implementor(root->right, count);

    if(!leftSubtree || !rightSubtree)
        return false;

    if(root->left && root->data != root->left->data)
        return false;

    if(root->right && root->data != root->right->data)
        return false;

    count++;
    return true;
}

int countSingle(Node* root) {
    int count = 0;
    implementor(root, count);
    return count;
}


int main() 
{ 
    /* Let us construct the below tree 
            4 
          /   \ 
        4      5 
      /  \      \ 
     4    4      5 */
    Node* root        = newNode(4); 
    root->left        = newNode(4); 
    root->right       = newNode(5); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(4); 
    root->right->right = newNode(5); 
  
    cout << "Count of Single Valued Subtrees is "
         << countSingle(root); 
    return 0; 
} 
