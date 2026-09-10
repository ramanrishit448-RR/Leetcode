class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Duplicate found: skip the next node
                current->next = current->next->next;
            } else {
                // Move to the next unique node
                current = current->next;
            }
        }

        return head;
    }
};