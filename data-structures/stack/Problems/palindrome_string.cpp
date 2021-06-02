// Find if a string is Palindrome using stack

#include <stack>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

namespace findPalindrome {
    // Keep only alphabets in the string and remove other characters
    void processInputString(string &inp_str) {
        int valid_index = 0, invalid_chars=0;
        for(string::iterator iter = inp_str.begin();iter!= inp_str.end();iter++) {
            if(isalpha(*iter)) {
                inp_str.at(valid_index) = tolower(*iter);
                valid_index++;
            } else {
                invalid_chars++;
            }
        }
        cout << "Number of invalid characters : " << invalid_chars << endl;
        inp_str.erase((inp_str.size()-invalid_chars),string::npos);
    }

    // Push first half of the string and compare second half by Pop
    bool findIfPalindrome(const string &inp_str) {
        cout << "Processing on string : " << inp_str << endl;
        int length = inp_str.length();
        if(length <= 0) return false;
        int mid_elem = length/2;

        stack<char> pal_stack;
        for(int it=0;it < mid_elem;it++) {
            char tmp = tolower(inp_str.at(it));
            pal_stack.push(tmp);
        }

        if(length%2 != 0) {
            mid_elem++;
        }

        for(int it=mid_elem;it < length;it++) {
            char tmp = pal_stack.top();
            pal_stack.pop();
            if(inp_str.at(it) != tmp) {
                return false;
            }
        }
        return true;
    }
}



int main()
{
    char user_choice = 'y';
    while('y' == tolower(user_choice)) {
        cout << "Continue(y/n) ?" << endl;
        cin >> user_choice;
        if(user_choice != 'y') break;
        string dis_str("Enter input string"), inp_str;
        cout << dis_str << endl;
        cin.sync();
        getline(cin, inp_str);

        findPalindrome::processInputString(inp_str);
        if(findPalindrome::findIfPalindrome(inp_str)) {
            cout << inp_str << " is a Palindrome" << endl;
        } else {
            cout << inp_str << " is not a Palindrome" << endl;
        }
    }
}
