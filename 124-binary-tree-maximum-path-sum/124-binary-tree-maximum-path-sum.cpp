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
    
    int solve(TreeNode* root,int&ans)
    {
        if(!root)return 0;
        int l = solve(root->left,ans);
        int r= solve(root->right,ans);
        ans = max(ans,l+r+root->val);
        ans = max(ans,max(max(root->val+l,root->val+r),root->val));
        int d= max(max(root->val+l,root->val+r),root->val);
        // cout<<"D"<<d<<"ans"<<ans<<endl;
        return d;
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int ans = INT_MIN;
        int a = solve(root,ans);
        return ans;
        
    }
};