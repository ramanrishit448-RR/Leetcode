class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;

        while (true) {
            // Step 1: Check if there are at least k nodes left
            ListNode* kthNode = prevGroupTail;
            for (int i = 0; i < k && kthNode != nullptr; i++) {
                kthNode = kthNode->next;
            }
            if (!kthNode) break; // Less than k nodes left, stop reversing

            // Step 2: Reverse k nodes in-place
            ListNode* groupStart = prevGroupTail->next;
            ListNode* nextGroupHead = kthNode->next;
            
            ListNode* curr = groupStart;
            ListNode* prev = nextGroupHead; // Point the end of reversed segment to next group
            
            while (curr != nextGroupHead) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Step 3: Reconnect with the rest of the list
            prevGroupTail->next = kthNode;
            prevGroupTail = groupStart;
        }

        return dummy.next;
    }
};