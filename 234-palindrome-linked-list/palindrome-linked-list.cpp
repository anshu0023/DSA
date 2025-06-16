class Solution {
public:
    // Helper to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow);

        // Step 3: Compare both halves
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool isPalin = true;
        while (p2) {
            if (p1->val != p2->val) {
                isPalin = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return isPalin;
    }
};
