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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* curr=head;
        while(curr and count<k)
        {
            curr=curr->next;
            count++;
        }
        if(count<k)return head;
        curr=head;
        count=0;
        ListNode* prev=NULL;
        ListNode* tmp=NULL;
        while(count<k)
        {
            tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
            count++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};