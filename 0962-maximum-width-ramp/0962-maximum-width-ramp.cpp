#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        int n = nums.size();
        std::stack<int> st;

        // Step 1: Push indices of a strictly decreasing sequence
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int maxWidth = 0;

        // Step 2: Traverse from right to left to find maximum width
        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                maxWidth = std::max(maxWidth, j - st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};