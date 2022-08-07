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
    // vector<int>res;
public:
    // void solve(TreeNode* root)
    // {
    //     if(!root)return;
    //     solve(root->left);
    //     res.push_back(root->val);
    //     solve(root->right);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // solve(root);
        // return res;
        stack<TreeNode*>st;
        vector<int>res;
        TreeNode* curr =root;
        while(curr!=NULL or !st.empty())
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }
        return res;
    }
};