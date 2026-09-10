class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node pointing to the head
        ListNode dummy(0, head);
        ListNode* curr = &dummy;
        
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // Skip the node with the target value
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // Free memory in C++
            } else {
                // Move to the next node
                curr = curr->next;
            }
        }
        
        return dummy.next;
    }
};