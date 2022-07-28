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
        
        ListNode* prev=NULL;
        ListNode* curr = NULL;
        while(l1)
        {
            curr=l1;
            l1=l1->next;
            curr->next=prev;
            prev=curr;
        }
        // cout<<"YES"<<endl;
        l1=prev;
        prev=NULL;
        while(l2)
        {
            curr=l2;
            l2=l2->next;
            curr->next=prev;
            prev=curr;
        }
        // cout<<"YES"<<endl;
        l2=prev;
        ListNode* a = new ListNode(0);
        curr = a;
        int count=0;
        while(l1!=NULL or l2!=NULL or count!=0)
        {
            int sum=count;
            sum+=l1? l1->val:0;
            sum+=l2? l2->val:0;
            // cout<<"SUM"<<sum<<endl;
            curr->next=new ListNode(sum%10);
            count=sum/10;
            curr=curr->next;
            l1=l1? l1->next:nullptr;
            l2=l2? l2->next:nullptr;
            // cout<<count<<endl;
        }
        curr=a;
        a=a->next;
        curr->next=NULL;
        prev=NULL;
        while(a)
        {
            curr=a;
            a=a->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }
};