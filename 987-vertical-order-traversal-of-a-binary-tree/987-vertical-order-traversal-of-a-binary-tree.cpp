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
struct cell{
    TreeNode* a;
    int r=0,c=0;
    cell(TreeNode* b, int e,int d)
    {
        a=b,r=e,c=d;
    }
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue<cell>q;
        q.push(cell(root,0,0));
        map<int,vector<pair<int,int>>>mp;
        int mx = INT_MIN,mn=INT_MAX;
        while(!q.empty())
        {
            auto d = q.front();
            q.pop();
            mp[d.c].push_back({d.r,d.a->val});
            mn= min(d.c,mn);
            mx= max(d.c,mx);
            if(d.a->left)q.push(cell(d.a->left,d.r+1,d.c-1));
            if(d.a->right)q.push(cell(d.a->right,d.r+1,d.c+1));
            
        }
        vector<vector<int>>res;
        for(int i=mn;i<=mx;i++){
            sort(mp[i].begin(),mp[i].end());
            vector<int>vec;
            for(int j=0;j<mp[i].size();j++)
            {
                vec.push_back(mp[i][j].second);
            }
            res.push_back(vec);
        }
        return res;
    }
};