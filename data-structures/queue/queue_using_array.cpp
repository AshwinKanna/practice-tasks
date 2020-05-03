#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

const short queue_size = 8;
int queue_array[queue_size];
char front = -1, rear = -1;


void handle_enqueue()
{
    if(rear >= queue_size-1)
    {
        cout << endl << "Queue is already full. Please dequeue to enqueue further";
        return;
    }

    int tmp_elem;
    cout << endl << "Enter element : ";
    cin >> tmp_elem;

    if(front == -1)
    {
        front = 0;
    }
    
    rear++;
    queue_array[rear] = tmp_elem;
    cout << endl << "Element : " << tmp_elem << " added to queue successfully";
}

void handle_dequeue()
{
    if(front < 0)
    {
        cout << endl << "Queue is empty";
        return;
    }

    int tmp = queue_array[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }

    cout << endl << "Element : " << tmp << " removed from queue succeessfully";
}

void display_elements()
{
    cout << endl;
    if(front == -1 || rear == -1)
    {
        cout << endl << "Queue is empty";
        return;
    }
    for(int iter = front;iter <= rear;iter++)
    {
        cout << queue_array[iter] << "\t";
    }
}

int main()
{
    string control_message = "Please choose any option : 1.Enqueue 2.Dequeue 3.DisplayElements 4.GetCount 5.Exit";
    bool exit_flag = false;

    while(!exit_flag)
    {
        unsigned char user_option = 0;
        cout << endl << control_message << endl;
        cin >> user_option;

        switch(user_option)
        {
            case '1': 
                handle_enqueue();
                break;
            case '2':
                handle_dequeue();
                break;
            case '3':
                display_elements();
                break;
            case '4':
                if(front != -1 || rear != -1)
                {
                    cout << endl << "Currently, queue size is : " << abs(rear-front)+1;
                }
                else
                {
                    cout << endl << "Currently, queue size is : " << 0;
                }
                break;
            case '5':
                cout << endl << "Thank you for using the queue";
                exit_flag = true;
                break;
            default:
                cout << endl << "Invalid option specified. Please choose available options";
                break;
        }
    }

    return 1;
}