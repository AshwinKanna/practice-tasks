// Construct Complete Binary Tree from an array
// Left child of element at index i = 2i+1
// Right child of element at index i = 2i+2

#include <iostream>

using std::cout;
using std::endl;

class node
{
    public:
    int value;
    node *left = nullptr;
    node *right = nullptr;
};

class complete_b_tree
{
    public:
    complete_b_tree(int size)
    {
        root = nullptr;
        num_of_elements = size;
    }
    node *create_tree(int[], int index=0);
    node *create_new_node(int);
    void inorder_traversal(node*);
    void display();

    private:
    node *root;
    int num_of_elements;
};

node* complete_b_tree::create_new_node(int value)
{
    node* new_node = new node();
    new_node->value = value;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}

node* complete_b_tree::create_tree(int arr[], int index)
{
    if(index < num_of_elements)
    {
        node* Node;
        Node = create_new_node(arr[index]);
        if(index == 0)
        {
            this->root = Node;
        }
        Node->left = create_tree(arr, (2*index+1));
        Node->right = create_tree(arr, (2*index+2));
        return Node;
    }
    return nullptr;
}

void complete_b_tree::inorder_traversal(node* root)
{
    if(root == nullptr)
    {
        return;
    }
    inorder_traversal(root->left);
    cout << root->value << "\t";
    inorder_traversal(root->right);
}

void complete_b_tree::display()
{
    cout << "Elements in the Tree are - " << endl;
    inorder_traversal(root);
}

int main()
{
    int inp_arr[] = {1,2,3,4,5,6,6,6,6};
    int size = sizeof(inp_arr)/sizeof(inp_arr[0]);

    complete_b_tree inst(size);
    inst.create_tree(inp_arr);
    inst.display();
    
}
