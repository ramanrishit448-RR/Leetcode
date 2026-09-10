class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        
        // Move first pointer to the k-th node
        for (int i = 1; i < k; ++i) {
            first = first->next;
        }

        // Use two-pointer approach to find the k-th node from the end
        ListNode* temp = first;
        ListNode* second = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            second = second->next;
        }

        // Swap values in-place
        swap(first->val, second->val);

        return head;
    }
};