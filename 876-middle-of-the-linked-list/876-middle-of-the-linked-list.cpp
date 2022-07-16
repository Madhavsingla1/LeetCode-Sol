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
    ListNode* middleNode(ListNode* head) {
        ListNode *n = head;
        int count=0;
        while(n->next!=NULL)
        {
            n=n->next;
            count++;
        }
        int d= (count+1)/2;
        while(d--)
        {
            head=head->next;
        }
        return head;
        
    }
};