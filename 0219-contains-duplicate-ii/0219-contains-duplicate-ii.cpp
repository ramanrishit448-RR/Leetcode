#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            // If the current number is already in the set, we found a match within distance k
            if (window.count(nums[i])) {
                return true;
            }
            // Add the current number to the set
            window.insert(nums[i]);

            // If the window size exceeds k, remove the oldest element
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};