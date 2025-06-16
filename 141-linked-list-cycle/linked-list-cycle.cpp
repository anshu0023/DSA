/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       int count = 0;
        while (head != NULL) {
            count++;
            if (count > 10000) return true;
            head = head->next;
        }
        return false;
    }
};
