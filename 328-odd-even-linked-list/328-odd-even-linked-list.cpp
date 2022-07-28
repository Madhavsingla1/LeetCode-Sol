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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenstart=NULL;
        ListNode* evenend = NULL;
        ListNode* oddstart = NULL;
        ListNode* oddend = NULL;
        ListNode* curr = head;
        int val=0;
        while(curr)
        {
            if(val%2==0)
            {
                if(evenstart==NULL)
                {
                    evenstart=curr;
                    evenend=evenstart;
                }
                else
                {
                    evenend->next=curr;
                    evenend=evenend->next;
                }
            }
            else 
            {
                if(oddstart==NULL)
                {
                    oddstart=curr;
                    oddend=oddstart;
                }
                else
                {
                    oddend->next=curr;
                    oddend=oddend->next;
                }
            }
            // cout<<"YES"<<endl;
            curr=curr->next;
            val++;
        }
        if(!head or !head->next)return head;
        head=evenstart;
        evenend->next=oddstart;
        oddend->next=NULL;
        return head;
        
        
    }
};