class Solution {
public:
    bool isValid(string s) {
        string stack;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push_back(c);
            } else {
                if (stack.empty()) return false;
                
                char top = stack.back();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
                
                stack.pop_back();
            }
        }
        
        return stack.empty();
    }
};