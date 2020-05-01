#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

const short stack_size = 4;
int stack_array[stack_size];
char top = -1;

bool handle_push()
{
    if(top == stack_size-1)
    {
        cout << endl << "Stack is already full. Please pop to push further";
        return false;
    }

    int tmp_elem;
    cout << endl << "Enter element : ";
    cin >> tmp_elem;

    top++;
    stack_array[top] = tmp_elem;
    cout << endl << "Element : " << tmp_elem << " added to stack successfully";
    return true;
}

void handle_pop()
{
    if(top < 0)
    {
        cout << endl << "Stack is empty";
        return;
    }

    cout << endl << "Element : " << stack_array[top] << " removed from stack successfully";
    top--;
}

void display_elements()
{
    if(top < 0)
    {
        cout << endl << "Stack is empty";
        return;
    }
    cout << endl;
    for(int iter = 0;iter <= top;iter++)
    {
        cout << stack_array[iter] << "\t";
    }
}


int main()
{
    string control_message = "Please choose any option : 1.Push 2.Pop 3.DisplayElements 4.GetCount 5.Exit";
    bool exit_flag = false;

    while(!exit_flag)
    {
        unsigned char user_option = 0;
        cout << endl << control_message << endl;
        cin >> user_option;

        switch(user_option)
        {
            case '1': 
                handle_push();
                break;
            case '2':
                handle_pop();
                break;
            case '3':
                display_elements();
                break;
            case '4':
                cout << endl << "Currently, stack size is : " << top+1;
                break;
            case '5':
                cout << endl << "Thank you for using the stack";
                exit_flag = true;
                break;
            default:
                cout << endl << "Invalid option specified. Please choose available options";
                break;
        }
    }

    return 1;
}