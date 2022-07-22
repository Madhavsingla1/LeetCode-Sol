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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* s = list1;
        ListNode* d=NULL;
        int count=0;
        while(s->next)
        {
            // cout<<s->val<<endl;
            if(count==a-1)
                d=s;
            if(count==b+1)break;
            count++;
            s=s->next;
        }
        d->next=list2;
        while(list2->next)
        {
            list2=list2->next;
        }
        list2->next=s;
        return list1;
    }
};