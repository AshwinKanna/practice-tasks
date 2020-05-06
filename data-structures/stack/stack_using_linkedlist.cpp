#include <iostream>
#include <string>
#include <cstring>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define stack_max_count 20

struct stack_element
{
    int elem;
    stack_element *link = nullptr;
};

class stack
{
    public:
        int count = 0;
        int max_count = stack_max_count;
        stack_element *top = nullptr;
};

void handle_push(stack* &my_stack)
{
    if(my_stack->count >= my_stack->max_count)
    {
        cout << endl << "Stack is already full. Please pop to push further";
        return;
    }

    int tmp;
    cout << endl << "Enter element : ";
    cin >> tmp;

    stack_element *tmp_elem = new stack_element;
    tmp_elem->elem = tmp;

    if(my_stack->top == nullptr)
    {
        my_stack->top = tmp_elem;
    }
    else
    {
        tmp_elem->link = my_stack->top;
        my_stack->top = tmp_elem;
    }
    my_stack->count += 1;
}

void handle_pop(stack* &my_stack)
{
    if(my_stack->count <= 0)
    {
        cout << endl << "Stack is empty";
        return;
    }

    stack_element *element_to_be_popped = my_stack->top;
    int elem_value = element_to_be_popped->elem;
    my_stack->top = element_to_be_popped->link;
    my_stack->count -= 1;
    delete(element_to_be_popped);
    cout << endl << "Element : " << elem_value << " removed from stack successfully";
}

void display_elements(stack* &my_stack)
{
    stack_element *iter = my_stack->top;

    if(iter == nullptr)
    {
        cout << endl << "No elements in the stack";
        return;
    }

    while(iter != nullptr)
    {
        cout << iter->elem << "\t";
        iter = iter->link;
    }
}

int main()
{
    string control_message = "Please choose any option : 1.Push 2.Pop 3.DisplayElements 4.GetCount 5.Exit";
    bool exit_flag = false;

    stack *my_stack = new stack();

    while(!exit_flag)
    {
        unsigned char user_option = 0;
        cout << endl << control_message << endl;
        cin >> user_option;

        switch(user_option)
        {
            case '1': 
                handle_push(my_stack);
                break;
            case '2':
                handle_pop(my_stack);
                break;
            case '3':
                display_elements(my_stack);
                break;
            case '4':
                cout << endl << "Currently, stack size is : " << my_stack->count;
                break;
            case '5':
                cout << endl << "Thank you for using the stack(using linkedList)";
                exit_flag = true;
                break;
            default:
                cout << endl << "Invalid option specified. Please choose available options";
                break;
        }
    }

    return 1;
}