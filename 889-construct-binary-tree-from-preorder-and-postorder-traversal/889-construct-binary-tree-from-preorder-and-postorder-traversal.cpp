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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,int i,int j,int i1,int j1)
    {
        // cout<<"i "<<i<<" j "<<j<<" i1 "<<i1<<" j1 "<<j1<<endl;
        if(i1>j1){return NULL;}
        TreeNode* root = new TreeNode(preorder[i]);
        if(i+1>j)return root;
        int d= mp[preorder[i+1]];
        // cout<<"root "<<root->val<<endl;
        // cout<<"i "<<i+1<<" j "<<d-i1+i+1<<" post i "<<i1<<" j "<<d<<endl;
        root->left = solve(preorder,postorder,i+1,d-i1+i+1,i1,d);
        // cout<<"i "<<d-i1+i+2<<" j "<<j<<" post i "<<d+1<<" j "<<j1-1<<endl;
        root->right = solve(preorder,postorder,d-i1+i+2,j,d+1,j1-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        int n=preorder.size();
        for(int i=0;i<n;i++)
            mp[postorder[i]]=i;
        return solve(preorder,postorder,0,n-1,0,n-1);
        
    }
};