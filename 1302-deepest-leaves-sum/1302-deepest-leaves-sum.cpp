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
    pair<int,int>res={0,0};
public:
    void solve(TreeNode* root, int len)
    {
        if(!root)return;
        if(len>res.first)
        {
            res.second=root->val;
            res.first=len;
        }
        else if(len==res.first)
        {
            res.second+=root->val;
        }
        solve(root->left,len+1);
        solve(root->right,len+1);
    }
    int deepestLeavesSum(TreeNode* root) {
     solve(root,1);
        return res.second;
    }
};