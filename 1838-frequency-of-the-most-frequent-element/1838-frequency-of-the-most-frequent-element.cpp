class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int maxLen = 0;
        long sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            while (long(nums[right]) * (right - left + 1) - sum > k) {
                sum = sum - nums[left];
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};