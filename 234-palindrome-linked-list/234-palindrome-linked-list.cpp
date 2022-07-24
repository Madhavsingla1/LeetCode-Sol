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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=NULL;
        ListNode* prev=NULL;
        while(slow)
        {
            curr=slow;
            slow=slow->next;
            curr->next=prev;
            prev=curr;
        }
        while(prev and head)
        {
            if(head->val!=prev->val)return 0;
            head=head->next;
            prev=prev->next;
        }
        return 1;
    }
};