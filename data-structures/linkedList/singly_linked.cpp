#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Element
{
    public:
        int data;
        Element *next;
};

Element *createElement(int value)
{
    Element *p_new_element = new Element();
    p_new_element->data = value;
    p_new_element->next = nullptr;

    return p_new_element;
}

unsigned short getCount(Element *p_head)
{
    Element *iter = p_head;
    unsigned short num_elems = 0;
    while(iter != nullptr)
    {
        num_elems++;
        iter = iter->next;
    }
    return num_elems;
}

void insert_front(Element *&p_head)
{
    int tmp_elem;
    cout << endl << "Enter element : ";
    cin >> tmp_elem;

    Element *p_tmp_element = createElement(tmp_elem);
    if(p_head == nullptr)
    {
        p_head = p_tmp_element;
    }
    else
    {
        p_tmp_element->next = p_head;
        p_head = p_tmp_element;
    }
}

void insert_last(Element *&p_head)
{
    int tmp_elem;
    cout << endl << "Enter element : ";
    cin >> tmp_elem;

    Element *p_tmp_element = createElement(tmp_elem);
    if(p_head == nullptr)
    {
        p_head = p_tmp_element;
    }
    else
    {
        Element *iterator = p_head;
        while(iterator->next != nullptr)
        {
            iterator = iterator->next;
        }
        iterator->next = p_tmp_element;
    }
}

void insert_at_pos(Element *&p_head)
{
    short tmp_pos;
    cout << endl << "Enter position with 1'based indexing : ";
    cin >> tmp_pos;

    if(tmp_pos < 2)
    {
        cout << endl << "Enter position with indexing starting from 2 or go with InsertFront option";
        return;
    }

    int tmp_elem;
    cout << endl << "Enter element : ";
    cin >> tmp_elem;

    short int size = getCount(p_head);
    if(tmp_pos > size)
    {
        cout << endl << "Enter position in the range 2 to " << size;
        return;
    }

    Element *p_tmp_element = createElement(tmp_elem);
    if(p_head == nullptr)
    {
        p_head = p_tmp_element;
    }
    else
    {
        Element *iter = p_head;
        unsigned char tmp_it_track = 1;
        while(tmp_it_track < (tmp_pos - 1))
        {
            iter = iter->next;
            tmp_it_track++;
        }
        p_tmp_element->next = iter->next;
        iter->next = p_tmp_element;
    }
}

void display(Element *p_head)
{
    Element *iter = p_head;

    if(iter == nullptr)
    {
        cout << endl << "No elements in the list";
        return;
    }

    while(iter != nullptr)
    {
        cout << iter->data << "\t";
        iter = iter->next;
    }
}

void delete_front(Element *&p_head)
{
    if(p_head == nullptr)
    {
        cout << endl << "No elements to delete";
        return;
    }
    else if(p_head->next == nullptr)
    {
        delete(p_head);
        p_head = nullptr;
        return;
    }

    Element *tmp_elem = p_head;
    p_head = tmp_elem->next;
    delete(tmp_elem);
}

void delete_last(Element *&p_head)
{
    Element *iter = p_head;

    if(iter == nullptr)
    {
        cout << endl << "No elements to delete";
        return;
    }
    else if(iter->next == nullptr)
    {
        delete(iter);
        p_head = nullptr;
        return;
    }

    while(iter->next->next != nullptr)
    {
        iter = iter->next;
    }

    delete(iter->next);
    iter->next = nullptr;
}

void delete_at_pos(Element *&p_head)
{
    if(p_head == nullptr)
    {
        cout << endl << "No elements to delete";
        return;
    }
    else if(p_head->next == nullptr)
    {
        delete(p_head);
        p_head = nullptr;
        return;
    }

    short tmp_pos;
    cout << endl << "Enter position with 1'based indexing : ";
    cin >> tmp_pos;

    if(tmp_pos < 2)
    {
        cout << endl << "Enter position with indexing starting from 2 or go with DeleteFront option";
        return;
    }

    short int size = getCount(p_head);
    if(tmp_pos > size)
    {
        cout << endl << "Enter position in the range 2 to " << size;
        return;
    }

    Element *iter = p_head;

    unsigned char tmp_it_track = 1;
    while(tmp_it_track < (tmp_pos - 1))
    {
        tmp_it_track++;
        iter = iter->next;
    }
    Element *elem_to_del = iter->next;
    iter->next = elem_to_del->next;
    delete(elem_to_del);
}


int main()
{
    string control_message = "Please choose any option : 1.InsertFront 2.InsertLast 3.InsertAtPos 4.DeleteFront 5.DeleteLast 6.DeleteAtPos 7.Display 8.GetCount 9.Exit";
    bool exit_flag = false;

    Element *p_head = nullptr;

    while(!exit_flag)
    {
        unsigned char user_option = 0;
        cout << endl << control_message << endl;
        cin >> user_option;

        switch(user_option)
        {
            case '1': 
                insert_front(p_head);
                break;
            case '2':
                insert_last(p_head);
                break;
            case '3':
                insert_at_pos(p_head);
                break;
            case '4':
                delete_front(p_head);
                break;
            case '5':
                delete_last(p_head);
                break;
            case '6':
                delete_at_pos(p_head);
                break;
            case '7':
                display(p_head);
                break;
            case '8':
                cout << endl << "No.of elements in the list : " << getCount(p_head);
                break;
            case '9':
                cout << endl << "Thank you for using the singly linked list";
                exit_flag = true;
                break;
            default:
                cout << endl << "Invalid option specified. Please choose available options";
                break;
        }
    }

    return 1;
}
