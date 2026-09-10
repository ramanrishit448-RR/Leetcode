class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size() - 1;
        int count = 0;

        while (l < r) {
            int sum = nums[l] + nums[r];

            if (sum < target) {
                count += (r - l);
                l++;
            }
            else {
                r--;
            }
        }

        return count;
    }
};