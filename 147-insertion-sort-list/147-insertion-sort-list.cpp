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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* net=head->next;
        head->next=NULL;
        while(net)
        {
            ListNode* curr =head;
            ListNode* a=NULL;
            while(curr and curr->val>net->val)
            {
                a=curr;
                curr=curr->next;
            }
            if(a)
            {
                ListNode* b= a->next;
                a->next=net;
                net=net->next;
                a->next->next=b;
            }
            else
            {
                a=net;
                net=net->next;
                a->next=curr;
                head=a;
            }
        }
        ListNode* curr=NULL;
        ListNode* prev=NULL;
        while(head)
        {
            curr=head;
            head=head->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }
};