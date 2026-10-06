class Solution {
public:
    bool isValid(string s) {
        string ch = "";
        int i = 0;

        while (i < s.length()) {
            char curr = s[i];

            if (curr == '(' || curr == '[' || curr == '{') {
                ch.push_back(curr);
            }

            else {
                if (ch.empty())
                    return false;

                char top = ch.back();
                if ((curr == ')' && top == '(') ||
                    (curr == ']' && top == '[') ||
                    (curr == '}' && top == '{')) {
                    ch.pop_back();
                } else {
                    return false;
                }
            }
            i++;
        }

        return ch.empty();
    }
};