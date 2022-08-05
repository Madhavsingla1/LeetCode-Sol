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
    TreeNode* solve(TreeNode* root)
    {
        if(!root)return NULL;
        TreeNode* l = solve(root->left);
        TreeNode* r = solve(root->right);
        // cout<<"L "<< (l?l->val:0) <<" R "<< (r?r->val:0) <<endl;
        // cout<<"Root"<< (root?root->val:0)<<endl;
        TreeNode* k = l;
        while(k and k->right)k=k->right;
        root->left=NULL;
        root->right=l;
        if(k)k->right=r;
        else root->right=r;
        return root;
    }
    void flatten(TreeNode* root) {
        root=solve(root);
    }
};