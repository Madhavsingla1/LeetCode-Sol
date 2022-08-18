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
    vector<vector<int>>res;
public:
    void solve(TreeNode* root,int t,vector<int>&vec)
    {
        if(!root)return;
        if(t ==root->val and !root->left and !root->right)
        {
            vec.push_back(root->val);
            res.push_back(vec);
            vec.pop_back();
            return;
        }
        vec.push_back(root->val);
        solve(root->left,t-root->val,vec);
        solve(root->right,t-root->val,vec);
        vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>vec;
        solve(root,targetSum,vec);
        return res;
    }
};