class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        int count = 0;

        // First window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        if (sum >= k * threshold) {
            count++;
        }

        // Slide window
        for (int i = k; i < n; i++) {
            sum += arr[i];
            sum -= arr[i - k];

            if (sum >= k * threshold) {
                count++;
            }
        }

        return count;
    }
};
