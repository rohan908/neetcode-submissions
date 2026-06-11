#include <vector>
#include <iostream>

class Solution {
public:
    bool isValid(string s) {
        // if you see either a new par or bracket, "(" or "{", then append it to a stack. If you find a closing one, then peek the top of the stack and if it doesn't match then return false
        vector<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push_back(s[i]);
                
            }
            else {
                if (stack.empty()){ //no front bracket
                    std::cout << "no front bracket" << std::endl;
                    return false;
                }

                char top = stack.back();

                if ((s[i] == ')' && top != '(') || (s[i] == '}' && top != '{') || (s[i] == ']' && top != '[')){
                    return false;
                }


                stack.pop_back(); 
            }
        }
        if (!(stack.empty())){ //more brackets than closing brackets, thus false
            return false; 
        }
        return true;
    }
};
