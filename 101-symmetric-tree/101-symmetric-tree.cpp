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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*>st;
        st.push(root->left);
        vector<int>vec,dec;
        if(root->left)vec.push_back(root->left->val);
        else vec.push_back(0);
        while(!st.empty() and st.top())
        {
            TreeNode* d = st.top();
            st.pop();
            if(d->left)
            {
                vec.push_back(d->left->val);
                st.push(d->left);
            }
            else vec.push_back(0);
            if(d->right)
            {
                vec.push_back(d->right->val);
                st.push(d->right);
            }
            else vec.push_back(0);
        }
        st.push(root->right);
        if(root->right)dec.push_back(root->right->val);
        else dec.push_back(0);
        while(!st.empty() and st.top())
        {
            TreeNode* d = st.top();
            st.pop();
            if(d->right)
            {
                dec.push_back(d->right->val);
                st.push(d->right);
            }
            else dec.push_back(0);
            if(d->left)
            {
                dec.push_back(d->left->val);
                st.push(d->left);
            }
            else dec.push_back(0);
        }
        // cout<<vec.size()<<" "<<dec.size()<<endl;
        if(vec.size()!=dec.size())return 0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]!=dec[i])return 0;
            // cout<<vec[i]<<" "<<dec[i]<<endl;
        }
        return 1;
    }
};