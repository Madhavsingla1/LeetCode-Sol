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
    long long solve(TreeNode* root,long long t)
    {
        if(!root)return 0;
        if(!root->left and !root->right)
        {
            return t==root->val?1:0;
        }
        long long ans = (t==root->val)+solve(root->left,t-root->val)+solve(root->right,t-root->val);
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        return solve(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};