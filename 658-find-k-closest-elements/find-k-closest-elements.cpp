class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {

        int low = 0;
        int high = arr.size() - k;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (x - arr[mid] > arr[mid + k] - x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return std::vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};