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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        while(!q.empty())
        {
            int size=q.size();
            long long mx = INT64_MIN;
            for(int i=0;i<size;i++)
            {
                TreeNode* d = q.front();
                q.pop();
                mx=max((long long)d->val,mx);
                if(d->left)q.push(d->left);
                if(d->right)q.push(d->right);
            }
            res.push_back(mx);
        }
        return res;
        
    }
};