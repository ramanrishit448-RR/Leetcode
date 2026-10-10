class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long totalK = k1 + k2;
        long long initialSum = 0;

        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            initialSum += diff[i];
        }

        if (initialSum <= totalK) {
            return 0;
        }

        map<long long, long long> counts;
        for (long long d : diff) {
            counts[d]++;
        }

        auto it = counts.rbegin();
        while (totalK > 0 && it != counts.rend()) {
            long long val = it->first;
            long long count = it->second;
            it++;
            
            if (val == 0) break;

            long long nextVal = (it == counts.rend()) ? 0 : it->first;
            long long diffVal = val - nextVal;
            long long operationsNeeded = diffVal * count;

            if (totalK >= operationsNeeded) {
                totalK -= operationsNeeded;
                counts[nextVal] += count;
                counts.erase(val);
            } else {
                long long decreaseCount = totalK / count;
                long long remainder = totalK % count;
                
                long long newVal = val - decreaseCount;
                counts[newVal] += count - remainder;
                counts[newVal - 1] += remainder;
                counts[val] -= count;
                if (counts[val] == 0) {
                    counts.erase(val);
                }
                totalK = 0;
            }
        }

        long long ans = 0;
        for (auto& p : counts) {
            ans += p.first * p.first * p.second;
        }
        return ans;
    }
};