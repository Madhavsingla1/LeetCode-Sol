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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>a,b;
        vector<int>res;
        TreeNode* emp= new TreeNode(INT_MAX);
        TreeNode *t1,*t2;
        // cout<<"1"<<endl;
        while(1)
        {
            while(root1)
            {
                a.push(root1);
                root1=root1->left;
            }
            while(root2)
            {
                b.push(root2);
                root2=root2->left;
            }
        // cout<<"2"<<endl;
            if(a.empty() and b.empty())
                break;
            t1=a.empty()?emp:a.top();
            t2=b.empty()?emp:b.top();
        // cout<<"3"<<endl;
            if(t1->val==t2->val)
            {
                res.push_back(t1->val);
                res.push_back(t2->val);
                a.pop();
                b.pop();
                root1=t1->right;
                root2=t2->right;
                
            }
            else if(t1->val>t2->val)
            {
                b.pop();
                res.push_back(t2->val);
                root2=t2->right;
            }
            else
            {
                a.pop();
                res.push_back(t1->val);
                root1=t1->right;
            }
        // cout<<"4"<<endl;
            
        }
        return res;
    }
};