
#include <string>
#include "singly_linked_list.hpp"

using namespace std;

template <class nodeType>
void handleListManipulation(nodeType &tmp) {

    linkedList<nodeType> my_list;
    string inp_string = "1.InsertAtStart 2.InsertAtEnd 5.DisplayElements 6.DisplayCount 7.Exit";
    bool loop_flag=true;

    do {
        char inp_ch;
        nodeType ch_val;
        cout << inp_string << endl;
        cin >> inp_ch;

        switch(inp_ch) {
            case '1': cout << "Enter value" << endl; cin >> ch_val;
                    my_list.insertAtStart(ch_val);
                    break;
            case '2': cout << "Enter value" << endl; cin >> ch_val;
                    my_list.insertAtEnd(ch_val);
                    break;
            case '5': my_list.displayElements();
                    break;
            case '6': cout << my_list.displayCount() << endl;
                    break;
            case '7': loop_flag=false;
                    break;
        }
    } while(loop_flag);
}



int main() {

    int a;
    float b;
    handleListManipulation(a);
    handleListManipulation(b);

}