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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        fast = slow;
        slow=slow->next;
        fast->next=NULL;
        ListNode* prev=NULL;
        ListNode* curr = NULL;
        while(slow)
        {
            curr=slow;
            slow=slow->next;
            curr->next=prev;
            prev=curr;
        }
        // while(prev)
        // {
        //     cout<<prev->val<<endl;
        //     prev=prev->next;
        // }
        // while(head)
        // {
        //     cout<<head->val<<endl;
        //     head=head->next;
        // }
        ListNode* res=head;
        while(prev and res)
        {
            ListNode* d=res->next;
            res->next=prev;
            prev=prev->next;
            res=res->next;
            res->next=d;
            res=res->next;
        }
    }
};