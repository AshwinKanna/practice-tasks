// Convert given Infix expression(either only Alphabets or only Digits) to respective Postfix forms
#include <stack>
#include <string>
#include <iostream>

using namespace std;

namespace infixToPostfix {

    int operatorPrecedence(const char &oper) {
        int prec = -1;
        switch(oper) {
            case '+' :
            case '-' : prec = 2; break;
            case '*' :
            case '/' : prec = 3; break;
            case '^' :
            case '%' : break;
            default : break;
        }
        return prec;
    }

    bool isOperand(const char &oper, bool isAlphabet=false) {
        if(isAlphabet) {
            if(((oper >= 65) && (oper <= 90)) || ((oper >= 97) && (oper <= 122))) {
                return true;
            }    
        }
        else if((oper >= 48) && (oper <= 57)) {
            return true;
        }
        return false;
    }

    void convertInfixToPostfix(string &inp_str, string &out_str) {
        stack<char> postfix_stack;
        for(string::iterator iter = inp_str.begin();iter!= inp_str.end();iter++) {
            if(*iter == '(') {
                postfix_stack.push(*iter);
            } else if(isOperand(*iter,true)) {
                out_str.push_back(*iter);
            } else if(*iter == ')') {
                while(!postfix_stack.empty()) {
                    char stack_top = postfix_stack.top();
                    postfix_stack.pop();
                    if(stack_top == '(') {
                        break;
                    } else {
                        out_str.push_back(stack_top);
                    }
                }
            } else {
                int char_prec = operatorPrecedence(*iter);
                if(postfix_stack.empty()) {
                    postfix_stack.push(*iter);
                    continue;
                }
                bool continue_flag = true;
                while(!postfix_stack.empty() && continue_flag) {
                    int top_prec = operatorPrecedence(postfix_stack.top());

                    if(char_prec <= top_prec) {
                        out_str.push_back(postfix_stack.top());
                        postfix_stack.pop();
                    } else {
                        continue_flag = false;
                    }
                }
                postfix_stack.push(*iter);
            }
        }

        while(!postfix_stack.empty()) {
            out_str.push_back(postfix_stack.top());
            postfix_stack.pop();
        }
        cout << "Postfix string is : " << out_str << endl;
    }

}

int main()
{
    char inp_char = 'y';
    while(true) {
        cout << "Continue(y/n) ?" << endl;
        cin >> inp_char;
        if(inp_char != 'y') break;
        cout << "Enter Infix expression" << endl;
        string inp_str, out_str;
        cin >> inp_str;

        infixToPostfix::convertInfixToPostfix(inp_str,out_str);
    }

}