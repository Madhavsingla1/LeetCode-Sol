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
    
    void solve(TreeNode* root,int k,int &l)
    {
        if(!root)return ;
        solve(root->left,k,l);
        l++;
        if(l>=k)
        {
            if(l==k)res = root->val;
            return;
        }
        solve(root->right,k,l);
    }
    int kthSmallest(TreeNode* root, int k) {
        int a=0;
        solve(root,k,a);
        return res;
    }
};