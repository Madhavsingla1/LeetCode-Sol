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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>st;
        ListNode* curr=NULL;
        ListNode* prev=NULL;
        while(head)
        {
            curr=head;
            head=head->next;
            curr->next=prev;
            prev=curr;
        }
        head=prev;
        vector<int>res;
        while(prev)
        {
            while(!st.empty() and st.top()<=prev->val)
                st.pop();
            int val = st.empty()?0:st.top();
            res.push_back(val);
            st.push(prev->val);
            prev=prev->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};