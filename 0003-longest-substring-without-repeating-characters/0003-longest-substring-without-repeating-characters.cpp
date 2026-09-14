class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxLen = 0;
        int n = s.length();
        unordered_set<char> st;

        while (right < n) {
            // If character is already in the set, shrink window from the left
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            
            // Insert current character into the set
            st.insert(s[right]);
            
            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};