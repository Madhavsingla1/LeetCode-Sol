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
    bool res=1;
public:
    void solve(TreeNode* root, long long &a)
    {
        if(!root)return ;
        solve(root->left,a);
        if(a>=root->val)
        {
            res=0;
            return;
        }
        a=root->val;
        solve(root->right,a);
    }
    bool isValidBST(TreeNode* root) {
        long long a = -INT64_MAX;
        solve(root,a);
        return res;
    }
};