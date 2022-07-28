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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head)return NULL;
        ListNode* a=NULL;
        ListNode* b=head;
        ListNode* c=head->next;
        
        while(c)
        {
            bool flag=false;
            while(c and c->val==b->val)
            {
                flag=true;    
                c=c->next;
            }
            if(flag)
            {
                if(a==NULL)
                    head=c;
                else              
                    a->next=c;
                b=c;
                if(c)c=c->next;
            }
            else
            {
                a=b;
                b=c;
                if(c)c=c->next;
            }
        }
        return head;
    }
};