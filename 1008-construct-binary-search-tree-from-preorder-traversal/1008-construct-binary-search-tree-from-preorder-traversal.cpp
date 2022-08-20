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
    TreeNode* bstFromPreorder(vector<int>& pr) 
    {
        TreeNode* root= new TreeNode(pr[0]);
        stack<TreeNode*>st;
        st.push(root);
        for(int i=1;i<pr.size();i++)
        {
            TreeNode* d= st.top();
            st.pop();
            if(d->val>pr[i])
            {
                d->left = new TreeNode(pr[i]);
                st.push(d);
                st.push(d->left);
            }
            else if(st.size())
            {
                TreeNode* k = st.top();
                while(st.size() and k->val<pr[i])
                {
                    st.pop();
                    d=k;
                    if(st.size())k=st.top();
                }
                d->right = new TreeNode(pr[i]);
                st.push(d->right);
            }
            else
            {
                d->right = new TreeNode(pr[i]);
                st.push(d->right);
            }
        }
        return root;
    }
};