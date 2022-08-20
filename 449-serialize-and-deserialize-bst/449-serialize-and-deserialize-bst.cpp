/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        stack<TreeNode*>st;
        st.push(root);
        string res;
        while(st.size())
        {
            TreeNode* d = st.top();
            st.pop();
            res+=to_string(d->val)+".";
            if(d->right)st.push(d->right);
            if(d->left)st.push(d->left);
        }
        return res;
    }

    TreeNode* bst(string data,int &i,int mx)
    {
        if(i>=data.size())return nullptr;
        int j=i;
        while(j<data.size() and data[j]!='.')j++;
        int d = stoi(data.substr(i,j-i));
        if(d>mx)return nullptr;
        i=j+1;
        TreeNode* root = new TreeNode(d);
        root->left = bst(data,i,root->val);
        root->right= bst(data,i,mx);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()<=0)return nullptr;
        int i=0;
        return bst(data,i,INT_MAX);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;