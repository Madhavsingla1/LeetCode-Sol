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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a=new ListNode((l1->val+l2->val)%10);
        ListNode * b=a;
        int count=(l1->val+l2->val)/10;
        l1=l1->next;
        l2=l2->next;
        while(l1 and l2)
        {
            ListNode* c= new ListNode((l1->val+l2->val+count)%10);
            b->next=c;
            b=b->next;
            count=(l1->val+l2->val+count)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            ListNode* c= new ListNode((l1->val+count)%10);
            b->next=c;
            b=b->next;
            count=(l1->val+count)/10;
            l1=l1->next;
        }
        while(l2)
        {
            ListNode* c= new ListNode((l2->val+count)%10);
            b->next=c;
            b=b->next;
            count=(l2->val+count)/10;
            l2=l2->next;
        }
        if(count)
        {
            ListNode* c= new ListNode((count)%10);
            b->next=c;
            b=b->next;
        }
        return a;
    }
};