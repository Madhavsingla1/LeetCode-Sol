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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h= head;
        int count=1;
        while(h->next!=NULL)
        {
            count++;
            h=h->next;
        }
        if(count-n==0)
        {
            return head->next;
        }
        h=head;
        count=count-n-1;
        while(count--)
            h=h->next;
        
        h->next=h->next->next;
        return head;
        
    }
};