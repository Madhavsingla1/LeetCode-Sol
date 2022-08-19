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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        TreeNode* par=NULL;
        TreeNode* a = root;
        while(a)
        {
            par = a;
            if(a->val>val)
                a=a->left;
            else a=a->right;
        }
        if(par->val>val)
            par->left = new TreeNode(val);
        else 
            par->right = new TreeNode(val);
        return root;
    }
};