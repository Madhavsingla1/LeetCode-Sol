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
    int res=0;
public:
    void solve(TreeNode* root,int val)
    {
        if(!root)return ;
        if(root->val>=val)res++;
        solve(root->left,max(root->val,val));
        solve(root->right,max(root->val,val));
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
         solve(root,root->val);
        return res;
    }
    
};