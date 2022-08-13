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
    map<int,int>mp;
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int i,int j,int i1,int j1)
    {
        if(i1>j1)return NULL;
        TreeNode* root = new TreeNode(postorder[j]);
        int d= mp[postorder[j]];
        root->left = solve(inorder,postorder,i,i+d-i1-1,i1,d-1);
        root->right = solve(inorder,postorder,i+d-i1,j-1,d+1,j1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        return solve(inorder,postorder,0,n-1,0,n-1);
    }
};