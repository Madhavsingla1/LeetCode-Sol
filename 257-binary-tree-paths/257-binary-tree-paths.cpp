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
    vector<string>res;
public:
    
    void solve(TreeNode* root,string r)
    {
        if(!root)return;
        r+=to_string(root->val)+"->";
        if(!root->left and !root->right)
        {
            res.push_back(r.substr(0,r.size()-2));
            return;
        }
        solve(root->left,r);
        solve(root->right,r);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root,"");
        return res;
    }
};