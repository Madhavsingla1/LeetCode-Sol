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
struct Three{
    long long mx;
    long long mn;
    bool ans;
};
class Solution {
    // bool res=1;
public:
    // void solve(TreeNode* root, long long &a)
    // {
    //     if(!root)return ;
    //     solve(root->left,a);
    //     if(a>=root->val)
    //     {
    //         res=0;
    //         return;
    //     }
    //     a=root->val;
    //     solve(root->right,a);
    // }
    Three solve(TreeNode* root)
    {
        if(!root)return {INT64_MIN,INT64_MAX,true};
        Three l = solve(root->left);
        Three r = solve(root->right);
        Three ret;
        ret.ans = l.ans and r.ans and l.mx<root->val and root->val<r.mn;
        ret.mx = max({r.mx,l.mx,(long long)root->val});
        ret.mn = min({r.mn,l.mn,(long long)root->val});
        return ret;
    }
    bool isValidBST(TreeNode* root) {
        Three d = solve(root);
        return d.ans;
    }
};