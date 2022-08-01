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
    bool check(TreeNode* a, TreeNode*b)
    {
        if(!a and b)return 0;
        if(!b and a)return 0;
        if(!a and !b)return 1;
        return a->val==b->val and check(a->left,b->right) and check(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
      return check(root->left,root->right);
    }
};