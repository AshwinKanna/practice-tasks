#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


class deck
{
    public:
        deck()
        {
            front = -1;
            rear = -1;
        }
        void insert_first();
        void insert_last();
        void delete_first();
        void delete_last();
        bool is_full();
        bool is_empty();
        short get_queue_size() const;
        int get_queue_element(short) const;
    private:
        static const short queue_size = 8;
        int queue_array[queue_size];
        char front, rear;
};

int deck::get_queue_element(short elem_pos) const
{
    return this->queue_array[elem_pos];
}

short deck::get_queue_size() const
{
    return this->queue_size;
}

bool deck::is_full()
{
    if(this->front == this->rear + 1 || this->rear == (get_queue_size() - 1))
    {
        cout << endl << "Deque is ful";
        return true;
    }
    cout << endl << "Deque is not full";
    return false;
}

bool deck::is_empty()
{
    if(this->front == -1 && this->rear == -1)
    {
        cout << endl << "Deque is empty";
        return true;
    }
    cout << endl << "Deque is not empty";
    return false;
}

void deck::insert_first()
{
    if(is_full())
    {
        cout << endl << "Deque is already full.";
        return;
    }

    int element;
    cout << endl << "Enter element to be inserted first : ";
    cin >> element;

    if(this->front == -1)
    {
        this->front = 0;
        this->rear = 0;
    }
    else if(this->front == 0)
    {
        this->front = queue_size - 1;
    }
    else
    {
        this->front--;
    }
    queue_array[this->front] = element;
}

void deck::insert_last()
{
    if(is_full())
    {
        cout << endl << "Deque is already full.";
        return;
    }

    int element;
    cout << endl << "Enter element to be inserted first";
    cin >> element;

    if(this->rear == -1)
    {
        this->front = 0;
        this->rear = 0;
    }
    else if(this->rear == (get_queue_size() - 1))
    {
        this->rear = 0;
    }
    else
    {
        this->rear++;
    }
    queue_array[this->rear] = element;
}

void deck::delete_first()
{
    if(is_empty())
    {
        cout << endl << "Deque is currently empty";
        return;
    }

    cout << endl << "Element : " << get_queue_element(this->front) << " removed from Queue";
    if(this->front == this->rear)
    {
        this->front = -1;
        this->rear = -1;
        return;
    }

    this->front++;
    short q_size = get_queue_size();
    if(this->front >= q_size)
    {
        this->front %= q_size;
    }
}

void deck::delete_last()
{
    if(is_empty())
    {
        cout << endl << "Deque is currently empty";
        return;
    }

    cout << endl << "Element : " << get_queue_element(this->rear) << " removed from Queue";
    if(this->front == this->rear)
    {
        this->front = -1;
        this->rear = -1;
    }
    else if(this->rear == 0)
    {
        this->rear = (get_queue_size() - 1);
    }
    else
    {
        this->rear--;
    }
}


int main()
{
    // Input restricted DECK(Double Ended Queue)
    string control_message = "Please choose any option : 1.InsertFirst 2.DeleteFirst 3.DeleteLast 4.Is_Full? 5.Is_Empty? 6.Exit";
    bool exit_flag = false;

    deck input_res_deque;

    while(!exit_flag)
    {
        unsigned char user_option = 0;
        cout << endl << control_message << endl;
        cin >> user_option;

        switch(user_option)
        {
            case '1': 
                input_res_deque.insert_first();
                break;
            case '2':
                input_res_deque.delete_first();
                break;
            case '3':
                input_res_deque.delete_last();
                break;
            case '4':
                input_res_deque.is_full();
                break;
            case '5':
                input_res_deque.is_empty();
                break;
            case '6':
                cout << endl << "Thank you for using the Double Ended Queue";
                exit_flag = true;
                break;
            default:
                cout << endl << "Invalid option specified. Please choose available options";
                break;
        }
    }
    return 1;
}