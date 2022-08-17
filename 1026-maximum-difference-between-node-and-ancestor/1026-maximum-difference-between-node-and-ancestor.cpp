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
    pair<int,int>solve(TreeNode* root)
    {
        if(!root)return {-1e6,1e6};
        pair<int,int>l= solve(root->left);
        pair<int,int>r = solve(root->right);
        int d = root->val;
        res = max(res,max({l.first-d,r.first-d,d-l.second,d-r.second}));
        // cout<<"ROOT "<<root->val<<" l: "<<max({l.first,r.first,d})<<" R: "<<min({l.second,r.second,d})<<endl;
        return {max({l.first,r.first,d}),min({l.second,r.second,d})};
    }
    int maxAncestorDiff(TreeNode* root) {
        pair<int,int>m=solve(root);
        return res;
    }
};