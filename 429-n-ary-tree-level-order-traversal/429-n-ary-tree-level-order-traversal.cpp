/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(!root)return {}
;        queue<Node*>q;
        q.push(root);
        vector<vector<int>>res;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>vec;
            for(int i=0;i<n;i++)
            {
                auto d = q.front();
                q.pop();
                vec.push_back(d->val);
                auto k =d->children;
                for(int j=0;j<k.size();j++)
                    if(k[j])q.push(k[j]);
            }
            res.push_back(vec);
        }
        return res;
        
    }
};