
#include "bst_tree.hpp"
#include <string>
#include <string.h>
#include <stdio.h>


template <class nodeType>
void handleBst(nodeType tmp)
{
    std::string feeder_str = "1.New node 2.Inorder Display 9.Exit";
    bool ch_flag = true;
    char inp_ch;

    bst_tree<nodeType> my_bst;

    while(ch_flag) {
        std::cout << feeder_str << std::endl;
        std::cin >> inp_ch;
        std::cout << inp_ch;
        nodeType inp_value;

        switch(inp_ch) {
            case '1' : std::cout << "Enter input value" << std::endl;
                    std::cin >> inp_value;
                    my_bst.insertNode(inp_value);
                    break;
            case '2' : std::cout << "Inorder traversal" << std::endl;
                    my_bst.inOrderDisplay();
                    break;
            case '9' : 
            default  : ch_flag = false;
                     break;
        }
    }
    std::cout << "Thank you for using" << std::endl;
}


int main(void)
{
    char user_inp[50];// = "hello world";
    std::cout << "Enter a string input: " << std::endl;
    gets(user_inp);
    printf("%s", user_inp);


    char *tokenPtr = strtok(user_inp, " ");
    while(tokenPtr != NULL) {
        std::string s;
        std::cout << tokenPtr << std::endl;
        tokenPtr = strtok(NULL, " ");
        
    }


    // int a;
    // handleBst(a);

    // char c;
    // handleBst(c);

}