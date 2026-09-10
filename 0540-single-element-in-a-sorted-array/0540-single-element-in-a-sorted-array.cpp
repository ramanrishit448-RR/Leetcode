class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid and its paired index hold the same value
            if (nums[mid] == nums[mid ^ 1]) {
                // We are still in the left half, move right
                left = mid + 1;
            } else {
                // We are in the right half or at the single element
                right = mid;
            }
        }
        
        return nums[left];
    }
};