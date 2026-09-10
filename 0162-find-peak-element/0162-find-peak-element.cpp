class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Slope is rising, peak is to the right
                left = mid + 1;
            } else {
                // Slope is falling, peak is at mid or to the left
                right = mid;
            }
        }

        return left;
    }
};