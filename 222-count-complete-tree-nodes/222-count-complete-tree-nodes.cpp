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
    pair<bool,int> solve(TreeNode* root)
    {
        int a=0,b=0;
        TreeNode* tmp=root;
        while(tmp)
        {
            a++;
            tmp=tmp->left;
        }
        tmp=root;
        while(tmp)
        {
            b++;
            tmp=tmp->right;
        }
        return {a==b,a};
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        
        pair<bool,int>l = solve(root->left);
        pair<bool,int>r = solve(root->right);
        
        int cnt=1;
        if(l.first)
            cnt+=pow(2,l.second)-1;
        else 
            cnt+=countNodes(root->left);
        if(r.first)
            cnt+=pow(2,r.second)-1;
        else
            cnt+=countNodes(root->right);
        
        return cnt;
    }
};