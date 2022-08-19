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
    pair<TreeNode*,TreeNode*>nodeandpar(TreeNode* root,int key)
    {
        TreeNode* par = NULL;
        TreeNode* a = root;
        while(a and a->val!=key)
        {
            par = a;
            if(a->val>key)
                a= a->left;
            else a=a->right;
        }
        return {par,a};
    }
    bool isleaf(TreeNode* root){
        return (!root->left and !root->right);
    }
    void nodeleaf(TreeNode* par, TreeNode* root)
    {
        if(par->left == root)
            par->left = NULL;
        else par->right=NULL;
    }
    
    bool issingle(TreeNode* root){
        return (!root->left and root->right) or (!root->right and root->left);
    }
    void singlenode(TreeNode* par,TreeNode* root)
    {
        if(par->left==root)
        {
            if(root->left!=NULL)
                par->left = root->left;
            else par->left = root->right;
        }
        else 
        {
            if(root->left!=NULL)
                par->right = root->left;
            else par->right = root->right;
        }
        delete(root);
    }
    
    void bothnode(TreeNode* par,TreeNode* root)
    {
        TreeNode* d = root->left;
        TreeNode* k = NULL;
        while(d->right)
        {
            k=d;
            d=d->right;
        }
        if(k)
            k->right=d->left;
        
        if(d!=root->left)d->left =root->left;
        d->right = root->right;
        
        if(par->left ==root)
            par->left = d;
        else par->right = d;
        delete(root);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)return NULL;
        auto d = nodeandpar(root,key);
        if(!d.second)return root;
        if(d.second==root)
        {
            if(isleaf(root))
                return NULL;
            else if(issingle(root))
            {
                if(root->left)return root->left;
                else return root->right;
            }
            else
            {
                TreeNode* k= root->left;
                TreeNode* par =NULL;
                while(k->right)
                {
                    par = k;
                    k=k->right;
                }
                if(par)
                {
                    par->right = k->left;
                }
                if(k!=root->left)k->left = root->left;
                k->right = root->right;
                delete(root);
                return k;
            }
        }
       else { 
           if(isleaf(d.second))
            nodeleaf(d.first,d.second);
           else if(issingle(d.second))
             singlenode(d.first,d.second);
           else
               bothnode(d.first,d.second);
       }
        
        return root;
    }
};