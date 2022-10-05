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
    void solve(TreeNode* root,int val,int depth,int pos)
    {
        if(!root)return;
        if(pos == depth-1)
        {
            // cout<<root->val<<endl;
            TreeNode* a = root->left;
            TreeNode* b = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = a;
            root->right->right = b;
        }
        solve(root->left,val,depth,pos+1);
        solve(root->right,val,depth,pos+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        solve(root,val,depth,1);
        if(depth ==1)
        {
            TreeNode* res = new TreeNode(val);
            res->left = root;
            return res;
        }
        return root;
    }
};