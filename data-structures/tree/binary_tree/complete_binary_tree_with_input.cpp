// Construct Complete Binary Tree with input from User
// https://www.geeksforgeeks.org/linked-complete-binary-tree-its-creation/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#define MAX_SIZE 50

class node
{
    public:
    node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    int value;
    node *left;
    node *right;
};


class queue
{
    public:
    queue(int size)
    {
        this->size = size;
        this->front = this->rear = -1;
        this->alloc_queue();
    }

    int front, rear;
    int size;
    node* *array;

    void enqueue(node*);
    node* dequeue();
    bool is_full();
    bool is_empty();
    void alloc_queue();
    node* get_front();
};

void queue::alloc_queue()
{
    int size = this->size;
    this->array = new node*[size * sizeof(node*)];

    for(int i=0;i < this->size;++i)
    {
        this->array[i] = nullptr;
    }
}

bool queue::is_empty()
{
    if((this->front == -1) || (this->rear == -1) || (this->front > this->rear))
    {
        return true;
    }
    return false;
}

bool queue::is_full()
{
    if(this->rear == (this->size - 1))
    {
        return true;
    }
    return false;
}

node* queue::get_front()
{
    return this->array[this->front];
}

void queue::enqueue(node* new_node)
{
    if(this->is_full())
    {
        cout << endl << "Queue is full" ;
        return;
    }

    this->array[++this->rear] = new_node;

    if(this->front == -1)
    {
        this->front = 0;
    }

    cout << endl << "Element: " << new_node->value << " added to Queue";
}

node* queue::dequeue()
{
    if(this->is_empty())
    {
        cout << endl << "Queue is empty" ;
        return nullptr;
    }

    node* node_p = this->array[this->front];

    if(this->front == this->rear)
    {
        this->front = this->rear = -1;
    }
    else
    {
        ++this->front;
    }

    cout << endl << "Element: " << node_p->value << " removed from Queue";
    return node_p;
}

node* create_node(int value)
{
    node* new_node = new node(value);
    return new_node;
}

bool has_both_childs(node* &node_p)
{
    if((node_p != nullptr) && (node_p->left != nullptr) && (node_p->right != nullptr))
    {
        return true;
    }
    return false;
}

void handle_insertion(node* &root, queue* &node_queue)
{
    int elem;
    cout << endl << "Enter element: ";
    cin >> elem;

    node* new_node = create_node(elem);

    if(!root)
    {
        root = new_node;
    }
    else
    {
        node* front_node_in_queue = node_queue->get_front();

        if(front_node_in_queue->left == nullptr)
        {
            front_node_in_queue->left = new_node;
        }
        else if(front_node_in_queue->right == nullptr)
        {
            front_node_in_queue->right = new_node;
        }

        if(has_both_childs(front_node_in_queue))
        {
            node_queue->dequeue();
        }

    }
    node_queue->enqueue(new_node);
}


void handle_display(node* root)
{
    queue *tmp_queue = new queue(MAX_SIZE);

    if(!root)
    {
        cout << endl << "Tree is empty";
        return;
    }

    tmp_queue->enqueue(root);

    while(!tmp_queue->is_empty())
    {
        node* tmp_node = tmp_queue->dequeue();

        cout << endl << tmp_node->value;

        if(tmp_node->left)
        {
            tmp_queue->enqueue(tmp_node->left);
        }
        if(tmp_node->right)
        {
            tmp_queue->enqueue(tmp_node->right);
        }
    }
}


int main()
{
    string control_message = "Please choose any option : 1.Insert 2.Display 3.Exit";
    bool exit_flag = false;
    node *root = nullptr;
    queue *node_queue = new queue(MAX_SIZE);

    while(!exit_flag)
    {
        unsigned char user_option = 0;
        cout << endl << control_message << endl;
        cin >> user_option;

        switch(user_option)
        {
            case '1': 
                handle_insertion(root,node_queue);
                break;
            case '2':
                handle_display(root);
                break;
            case '3':
                cout << endl << "Thank you for using the Complete Binary Tree";
                exit_flag = true;
                break;
            default:
                cout << endl << "Invalid option specified. Please choose available options";
                break;
        }
    }

    return 1;
}
