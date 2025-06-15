class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

       
        int x = len - n;

        if (x == 0) {
            ListNode* newHead = head->next;
            head->next = NULL;
            delete head;
            return newHead;
        }

        ListNode* prev = head;
        ListNode* curr = prev->next;
        int i = 0;
        while (i < x - 1) {
            prev = prev->next;
            i++;
        }

        curr = prev->next;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        return head;
    }
};
