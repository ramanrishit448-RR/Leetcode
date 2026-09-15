class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0;       
        int right = 0;
        int maxLen = 0;
        int maxC = 0;

        while (right < s.size()) {
            freq[s[right]]++;
            maxC = max(maxC, freq[s[right]]);

            // Shrink window if required replacements exceed k
            while ((right - left + 1) - maxC > k) {
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1); 
            right++;
        }

        return maxLen;
    }
};