class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long sum = 0;
        long long maxSum = 0;

        unordered_map<int, int> mp;
        int dups = 0;

        // First window
        for (int i = 0; i < k; i++) {

            mp[nums[i]]++;

            if (mp[nums[i]] == 2) {
                dups++;
            }

            sum += nums[i];
        }

        if (dups == 0) {
            maxSum = max(maxSum, sum);
        }

        // Sliding window
        for (int i = k; i < nums.size(); i++) {

            int numToAdd = nums[i];
            int numToRemove = nums[i - k];

            // Add new number
            mp[numToAdd]++;

            if (mp[numToAdd] == 2) {
                dups++;
            }

            sum += numToAdd;

            // Remove old number
            if (mp[numToRemove] == 2) {
                dups--;
            }

            mp[numToRemove]--;

            sum -= numToRemove;

            // Check if all elements are distinct
            if (dups == 0) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};