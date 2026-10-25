class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // The majority element will always occupy the middle position
        return nums[nums.size() / 2];
    }
};