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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* j=head;
        ListNode* k = new ListNode(0);
        ListNode* d =k;
        // cout<<d->val<<endl;
        while(j)
        {
            int val=0;
            j=j->next;
            while(j and j->val!=0)
            {
                val+=j->val;
                j=j->next;
                // cout<<j->val<<endl;
            }
            if(val){d->next=new ListNode(val);
            d=d->next;}
        }
        return k->next;
        
    }
};