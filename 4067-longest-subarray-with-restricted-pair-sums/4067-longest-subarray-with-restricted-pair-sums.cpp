
class Solution {
public:
    int maxSubarray(std::vector<int>& nums) {
        int n = nums.size();
        

        int freq[501] = {0};
        int pair_sum[1001] = {0};
        
        int invalid_triples = 0;
        int max_len = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            int val = nums[r];

          
            invalid_triples += pair_sum[val];

     
            for (int v = 1; v <= 500; ++v) {
                if (freq[v] > 0) {
                    int sum = val + v;
                    pair_sum[sum] += freq[v];
               
                    if (sum <= 500) {
                        invalid_triples += freq[v] * freq[sum];
                    }
                }
            }

         
            freq[val]++;

            while (invalid_triples > 0) {
                int rem = nums[l];
                freq[rem]--;

                for (int v = 1; v <= 500; ++v) {
                    if (freq[v] > 0) {
                        int sum = rem + v;
                        pair_sum[sum] -= freq[v];
                        if (sum <= 500) {
                            invalid_triples -= freq[v] * freq[sum];
                        }
                    }
                }

   
                invalid_triples -= pair_sum[rem];

                l++;
            }

            max_len = std::max(max_len, r - l + 1);
        }

        return max_len;
    }
};