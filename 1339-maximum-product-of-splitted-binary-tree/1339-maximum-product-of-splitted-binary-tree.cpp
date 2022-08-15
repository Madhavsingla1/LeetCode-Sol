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
    long long res=0;
    int sum =0;
    int mod = 1e9+7;
public:
    int solve(TreeNode* root)
    {
        if(!root)return 0;
        return root->val=(root->val%mod+solve(root->left)%mod+solve(root->right)%mod)%mod;
    }
    void check(TreeNode* root)
    {
        if(!root)return;
        if(root->left)
        {
            res = max(res,(long long)(sum-root->left->val)*root->left->val);
            check(root->left);
        }
        if(root->right)
        {
            res = max(res,(long long)(sum-root->right->val)*root->right->val);
            check(root->right);
        }
    }
    int maxProduct(TreeNode* root) 
    {
        sum=solve(root);
        check(root);
        return res%mod;
    }
};