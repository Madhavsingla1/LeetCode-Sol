/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q,ans;
        q.push(original);
        ans.push(cloned);
        while(!q.empty())
        {
            TreeNode* d = q.front();
            q.pop();
            TreeNode* res = ans.front();
            ans.pop();
            // cout<<d->val<<endl;
            if(d==target)return res;
            
            if(d->right)
            {
                // cout<<"R"<<d->right->val<<endl;
                q.push(d->right);
                ans.push(res->right);
            }
            if(d->left)
            {
                // cout<<"L"<<d->left->val<<endl;
                q.push(d->left);
                ans.push(res->left);
            }
            
        }
        return NULL;
    }
};