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
struct Check{
    long long mx;
    long long mn;
    bool isbst;
    long long res;
};
class Solution {
    long long ans=0;
public:
    Check solve(TreeNode* root)
    {
        if(!root)return {INT64_MIN,INT64_MAX,true,0};
        Check l = solve(root->left);
        Check r = solve(root->right);
        Check ret;
        ret.mx = max({l.mx,r.mx,(long long)root->val});
        ret.mn = max(min({l.mn,r.mn,(long long)root->val}),0LL);
        ret.isbst = l.isbst and r.isbst and root->val>l.mx and root->val<r.mn;
        if(ret.isbst)
        {
            ret.res = root->val+l.res+r.res;
            ans=max(ret.res,ans);
        }
        else ret.res = max({l.res,r.res});
        return ret;
    }
    int maxSumBST(TreeNode* root) 
    {
         solve(root);
        return ans;
    }
};