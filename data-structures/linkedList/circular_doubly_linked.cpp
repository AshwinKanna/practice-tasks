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
        Element *prev;
        Element *next;
};

Element *createElement(int value)
{
    Element *p_new_element = new Element();
    p_new_element->data = value;
    p_new_element->prev = nullptr;
    p_new_element->next = nullptr;

    return p_new_element;
}

unsigned short getCount(Element *p_tail)
{
    Element *iter = p_tail;
    unsigned short num_elems = 0;
    if(iter == nullptr)
    {
        return num_elems;
    }
    else
    {
        num_elems = 1;
        iter = p_tail->next;
        while(iter != p_tail)
        {
            num_elems++;
            iter = iter->next;
        }
    }
    return num_elems;
}

void insert_front(Element *&p_tail)
{
    int tmp_elem;
    cout << endl << "Enter element : ";
    cin >> tmp_elem;

    Element *p_tmp_element = createElement(tmp_elem);
    if(p_tail == nullptr)
    {
        p_tail = p_tmp_element;
        p_tmp_element->prev = p_tmp_element;
        p_tmp_element->next = p_tmp_element;
    }
    else
    {
        p_tmp_element->next = p_tail->next;
        p_tmp_element->prev = p_tail;
        p_tmp_element->next->prev = p_tmp_element;
        p_tail->next = p_tmp_element;
    }
}

void insert_last(Element *&p_tail)
{
    int tmp_elem;
    cout << endl << "Enter element : ";
    cin >> tmp_elem;

    Element *p_tmp_element = createElement(tmp_elem);
    if(p_tail == nullptr)
    {
        p_tmp_element->prev = p_tmp_element;
        p_tmp_element->next = p_tmp_element;
        p_tail = p_tmp_element;
    }
    else
    {
        p_tmp_element->next = p_tail->next;
        p_tail->next->prev = p_tmp_element;
        p_tail->next = p_tmp_element;
        p_tmp_element->prev = p_tail;
        p_tail = p_tmp_element;
    }
}

void insert_at_pos(Element *&p_tail)
{
    short tmp_pos;
    cout << endl << "Enter position with 1'based indexing : ";
    cin >> tmp_pos;

    if(tmp_pos < 1)
    {
        cout << endl << "Enter position with indexing starting from 1";
        return;
    }

    short int size = getCount(p_tail);
    if(tmp_pos > (size + 1))
    {
        cout << endl << "Enter position in the range 1 to " << (size + 1) ;
        return;
    }

    int tmp_elem;
    cout << endl << "Enter element : ";
    cin >> tmp_elem;

    Element *p_tmp_element = createElement(tmp_elem);
    if(p_tail == nullptr)
    {
        p_tail = p_tmp_element;
        p_tmp_element->prev = p_tmp_element;
        p_tmp_element->next = p_tmp_element;
    }
    else
    {
        Element *iter = p_tail->next;
        unsigned char tmp_it_track = 1;
        while(tmp_it_track < (tmp_pos - 1))
        {
            iter = iter->next;
            tmp_it_track++;
        }

        if(tmp_pos == 1)
        {
            p_tmp_element->next = p_tail->next;
            p_tail->next->prev = p_tmp_element;
            p_tmp_element->prev = p_tail;
            p_tail->next = p_tmp_element;
            return;
        }

        p_tmp_element->next = iter->next;
        p_tmp_element->prev = iter;
        if(tmp_pos > size)
        {
            p_tmp_element->prev = p_tail;
            p_tail->next = p_tmp_element;
            p_tmp_element->next->prev = p_tmp_element;
            p_tail = p_tmp_element;
        }
        else
        {
            iter->next->prev = p_tmp_element;
            iter->next = p_tmp_element;
        }
    }
}

void display(Element *p_tail)
{
    Element *iter = p_tail;

    if(iter == nullptr)
    {
        cout << endl << "No elements in the list";
        return;
    }

    do
    {
        cout << iter->next->data << "\t";
        iter = iter->next;
    }while(iter != p_tail);
}

void delete_front(Element *&p_tail)
{
    if(p_tail == nullptr)
    {
        cout << endl << "No elements to delete";
        return;
    }
    else if(p_tail->next == p_tail)
    {
        delete(p_tail);
        p_tail = nullptr;
        return;
    }

    Element *tmp_elem = p_tail->next;
    p_tail->next = tmp_elem->next;
    p_tail->next->prev = p_tail;
    delete(tmp_elem);
}

void delete_last(Element *&p_tail)
{
    Element *iter = p_tail;

    if(iter == nullptr)
    {
        cout << endl << "No elements to delete";
        return;
    }
    else if(iter->next == p_tail)
    {
        delete(iter);
        p_tail = nullptr;
        return;
    }

    iter->prev->next = iter->next;
    iter->next->prev = iter->prev;
    p_tail = iter->prev;
    delete(iter);
}

void delete_at_pos(Element *&p_tail)
{
    if(p_tail == nullptr)
    {
        cout << endl << "No elements to delete";
        return;
    }
    else if(p_tail->next == p_tail)
    {
        delete(p_tail);
        p_tail = nullptr;
        return;
    }

    short tmp_pos;
    cout << endl << "Enter position with 1'based indexing : ";
    cin >> tmp_pos;

    if(tmp_pos < 1)
    {
        cout << endl << "Enter position with indexing starting from 1";
        return;
    }

    short int size = getCount(p_tail);
    if(tmp_pos > size)
    {
        cout << endl << "Enter position in the range 1 to " << size;
        return;
    }

    Element *iter = p_tail->next;

    unsigned char tmp_it_track = 1;
    while(tmp_it_track < (tmp_pos - 1))
    {
        tmp_it_track++;
        iter = iter->next;
    }

    if(tmp_pos == 1)
    {
        p_tail->next = iter->next;
        iter->next->prev = p_tail;
        delete(iter);
        return;
    }
    else
    {
        Element *elem_to_del = iter->next;
        if(elem_to_del == p_tail)
        {
            iter->next = elem_to_del->next;
            elem_to_del->next->prev = iter;
            p_tail = iter;
        }
        else
        {
            iter->next = elem_to_del->next;
            elem_to_del->next->prev = iter;
        }
        delete(elem_to_del);
    }
}


int main()
{
    string control_message = "Please choose any option : 1.InsertFront 2.InsertLast 3.InsertAtPos 4.DeleteFront 5.DeleteLast 6.DeleteAtPos 7.Display 8.GetCount 9.Exit";
    bool exit_flag = false;

    Element *p_tail = nullptr;

    while(!exit_flag)
    {
        unsigned char user_option = 0;
        cout << endl << control_message << endl;
        cin >> user_option;

        switch(user_option)
        {
            case '1': 
                insert_front(p_tail);
                break;
            case '2':
                insert_last(p_tail);
                break;
            case '3':
                insert_at_pos(p_tail);
                break;
            case '4':
                delete_front(p_tail);
                break;
            case '5':
                delete_last(p_tail);
                break;
            case '6':
                delete_at_pos(p_tail);
                break;
            case '7':
                display(p_tail);
                break;
            case '8':
                cout << endl << "No.of elements in the list : " << getCount(p_tail);
                break;
            case '9':
                cout << endl << "Thank you for using the circular doubly linked list";
                exit_flag = true;
                break;
            default:
                cout << endl << "Invalid option specified. Please choose available options";
                break;
        }
    }

    return 1;
}
