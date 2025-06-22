class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        // Dummy node
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy, *curr = &dummy, *nex = &dummy;
        int count = 0;
        
        // Count number of nodes
        while (curr->next) {
            curr = curr->next;
            count++;
        }
        
        // Loop while enough nodes to reverse
        while (count >= k) {
            curr = prev->next;
            nex = curr->next;
            for (int i = 1; i < k; ++i) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            count -= k;
        }
        return dummy.next;
    }
    
    ListNode* swapPairs(ListNode* head) {
        return reverseKGroup(head, 2);
    }
};
