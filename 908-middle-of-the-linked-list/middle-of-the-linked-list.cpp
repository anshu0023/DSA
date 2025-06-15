/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
             len++;
             temp=temp->next;
        }
        len = (len/2)+1;
        int i=0; 
        ListNode* curr = head;
        while(i<len-1){
           
            curr=curr->next;
            i++;
        }
        return curr;
    }
};