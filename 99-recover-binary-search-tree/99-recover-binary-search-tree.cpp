/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void solve(TreeNode* root,TreeNode* &r1, TreeNode* &r2, TreeNode* &r3,TreeNode* &prev,int &count)
    {
        if(!root)return;
        solve(root->left,r1,r2,r3,prev,count);
        if(!prev)prev=root;
        else
        {
            if(prev->val>root->val)
            {
                count++;
                if(count==1)
                {
                    // cout<<"YES"<<endl;
                    r1=prev;
                    r2=root;
                }
                else if(count==2)
                {
                    r3=root;
                }
            }
            prev=root;
        }
        solve(root->right,r1,r2,r3,prev,count);
    }
    
    void recoverTree(TreeNode* root) 
    {
        TreeNode* r1=nullptr,*r2=nullptr,*r3=nullptr,*prev=nullptr;
        int count=0;
        solve(root,r1,r2,r3,prev,count);
        if(count==1)
        {
            int d= r1->val;
            r1->val=r2->val;
            r2->val=d;
        }
        else
        {
            int d= r1->val;
            r1->val = r3->val;
            r3->val = d;
        }
    }
};