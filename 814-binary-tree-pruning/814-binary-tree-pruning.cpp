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
    bool solve(TreeNode* root)
    {
        if(!root)return false;
        if(!root->left and !root->right)
        {
            if(root->val==0)return false;
            return true;
        }
        root->left = solve(root->left)?root->left:NULL;
        root->right=solve(root->right)?root->right:NULL;
        if(!root->left and !root->right and root->val==0)return false;
            return true;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return solve(root)?root:NULL;
    }
};