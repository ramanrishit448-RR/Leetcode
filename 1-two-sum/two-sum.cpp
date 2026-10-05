#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> values;

        for (int i = 0; i < nums.size(); i++) {
            values.push_back({nums[i], i});
        }

        sort(values.begin(), values.end());

        int left = 0;
        int right = values.size() - 1;

        while (left < right) {
            int sum = values[left].first + values[right].first;

            if (sum == target) {
                return {values[left].second, values[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};
