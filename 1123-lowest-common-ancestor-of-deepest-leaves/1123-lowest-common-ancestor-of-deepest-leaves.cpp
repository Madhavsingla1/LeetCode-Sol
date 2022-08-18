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
    TreeNode* solve(TreeNode* root,TreeNode* a,TreeNode* b)
    {
        if(!root)return NULL;       
        if(root->val ==a->val or root->val == b->val)return root;
        TreeNode* l = solve(root->left,a,b);
        TreeNode* r = solve(root->right,a,b);
        if(!l)return r;
        if(!r)return l;
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* a;
        TreeNode* b;
        while(q.size())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                if(i==s-1)b=q.front();
                if(i==0)a=q.front();
                TreeNode* d = q.front();
                q.pop();
                if(d->left)q.push(d->left);
                if(d->right)q.push(d->right);
            }
        }
        return solve(root,a,b);
    }
};