class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                if (s[i - 1] == '(') {
                    score += (1 << depth);
                }
            }
            i++;
        }
        
        return score;
    }
};