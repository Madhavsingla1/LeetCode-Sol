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
    bool solve(TreeNode* r1,TreeNode* r2)
    {
        if(!r1 and !r2)return true;
        if(!r1 or !r2)return false;
        return r1->val==r2->val and solve(r1->left,r2->left) and solve(r1->right,r2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
        {
            return subRoot==NULL;
        }
        return solve(root,subRoot) or isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};