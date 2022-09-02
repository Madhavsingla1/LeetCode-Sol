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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>res;
        while(!q.empty())
        {
            int n = q.size();
            double sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* d = q.front();
                q.pop();
                sum+=d->val;
                if(d->left)q.push(d->left);
                if(d->right)q.push(d->right);
            }
            res.push_back(sum/n);
        }
        return res;
        
    }
};