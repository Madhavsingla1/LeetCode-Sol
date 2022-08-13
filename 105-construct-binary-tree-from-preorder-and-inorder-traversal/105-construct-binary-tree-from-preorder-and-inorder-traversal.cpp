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
    unordered_map<int,int>mp;
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int i,int j,int i1,int j1)
    {
        if(i>j)return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        int d = mp[preorder[i]];
        // cout<<root->val<<endl;
        // cout<<"Left"<<endl;
        // cout<<i+1<<"j "<<i+d-i1<<endl;
        root->left = solve(preorder,inorder,i+1,i+d-i1,i1,d-1);
        // cout<<"Right"<<endl;
        // cout<<i+d-i1+1<<"j "<<j<<endl;
        root->right = solve(preorder,inorder,i+d-i1+1,j,d+1,j1);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        return solve(preorder,inorder,0,n-1,0,n-1);
        
    }
};