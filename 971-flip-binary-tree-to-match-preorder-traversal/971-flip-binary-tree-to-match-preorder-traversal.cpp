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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) 
    {
        stack<TreeNode*>b;
        b.push(root);
        int i=0;
        vector<int>res;
        while(!b.empty())
        {
            TreeNode* d= b.top();
            b.pop();
            if(voyage[i++]!=d->val)return {-1};
            if(!d->left and !d->right)continue;
            if(d->left and voyage[i]==d->left->val)
            {
                if(d->right)b.push(d->right);
                b.push(d->left);
            }
            else{
                if(d->left){
                    b.push(d->left);
                    res.push_back(d->val);
                    }
                if(d->right)
                    b.push(d->right);
             }
        }
        return res;
    }
};