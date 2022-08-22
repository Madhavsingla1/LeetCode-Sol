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
    int res=0;
public:
    void solve(TreeNode* root,vector<int>vec)
    {
        if(!root)return;
        if(vec.size()>=2 and vec[vec.size()-2]%2==0)res+=root->val;
        vec.push_back(root->val);
        solve(root->left,vec);
        solve(root->right,vec);
        vec.pop_back();
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)return 0;
        solve(root,{});
        return res;
    }
};