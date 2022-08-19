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
    void solve(TreeNode* root,int& val)
    {
        if(!root)return;
        solve(root->right,val);
        root->val+=val;
        val = root->val;
        solve(root->left,val);
    }
    TreeNode* convertBST(TreeNode* root) {
        int a=0;
        solve(root,a);
        return root;
    }
};