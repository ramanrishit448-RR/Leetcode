class Solution {
public:
    int getNext(vector<int>& nums, int i, bool isForward) {
        bool currentDirection = nums[i] >= 0;
        // Direction mismatch -> invalid path
        if (isForward != currentDirection) return -1;

        int n = nums.size();
        int nextIndex = ((i + nums[i]) % n + n) % n;

        // Self-loop -> invalid cycle
        if (nextIndex == i) return -1;

        return nextIndex;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Skip elements already visited/invalidated
            if (nums[i] == 0) continue;

            bool isForward = nums[i] > 0;
            int slow = i, fast = i;

            while (true) {
                slow = getNext(nums, slow, isForward);
                fast = getNext(nums, fast, isForward);
                if (fast != -1) {
                    fast = getNext(nums, fast, isForward);
                }

                // Break if path direction changes or forms a self-loop
                if (slow == -1 || fast == -1) break;

                // Cycle detected
                if (slow == fast) return true;
            }

            // Mark visited elements on this failed path as 0 to avoid re-checking
            int curr = i;
            while (nums[curr] != 0 && (nums[curr] > 0) == isForward) {
                int nextIndex = ((curr + nums[curr]) % n + n) % n;
                nums[curr] = 0;
                curr = nextIndex;
            }
        }

        return false;
    }
};