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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int val=0;
        if(!root)
            return 0;
        if(root->left and !root->left->right and !root->left->left)val+=root->left->val;
        return val+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};