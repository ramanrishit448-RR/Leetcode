#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        int n = arr.size();
        
        // Min-heap storing tuples of: {fraction_value, numerator_index, denominator_index}
        using Element = std::tuple<double, int, int>;
        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;
        
        // Step 1: Push the smallest fraction for each denominator
        for (int j = 1; j < n; ++j) {
            pq.push({(double)arr[0] / arr[j], 0, j});
        }
        
        // Step 2: Extract top element k - 1 times
        for (int step = 0; step < k - 1; ++step) {
            auto [val, i, j] = pq.top();
            pq.pop();
            
            // Push the next smallest fraction with the same denominator
            if (i + 1 < j) {
                pq.push({(double)arr[i + 1] / arr[j], i + 1, j});
            }
        }
        
        // Step 3: The k-th smallest fraction
        auto [val, i, j] = pq.top();
        return {arr[i], arr[j]};
    }
};