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
    TreeNode* recoverFromPreorder(string t) {
        
        int i=0,j=i,cnt=0;
        while(j<t.size() and t[j]!='-')
        {
            j++,cnt++;
        }
        TreeNode* root = new TreeNode(stoi(t.substr(i,cnt)));
        map<int,TreeNode*>mp;
        mp[0]=root;
        i=j;
        while(i<t.size())
        {
            int count=0;
            while(i<t.size() and t[i]=='-'){count++;i++;}
            // cout<<"I:"<<i<<endl;
            j=i,cnt=0;
            while(j<t.size() and t[j]!='-')
            {
                j++;
                cnt++;
            }
            // cout<<"j:"<<j<<endl;
            TreeNode* toadd =  new TreeNode(stoi(t.substr(i,cnt)));
            // cout<<"count: "<<count<<endl;
            // cout<<"toadd: "<<toadd->val<<endl;
            // cout<<mp[count-1]->val<<endl;
            TreeNode* d= mp[count-1];
            if(!d->left)
            {
                d->left =toadd;
            }
            else d->right = toadd;
            mp[count]=toadd;
            i=j;
        }
        return root;
    }
    
};