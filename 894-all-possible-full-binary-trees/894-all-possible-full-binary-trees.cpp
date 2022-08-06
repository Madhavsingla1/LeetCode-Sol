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
    vector<TreeNode*> allPossibleFBT(int n) {
        // vector<TreeNode*>res;
        // res.push_back(NULL);
        if(n%2==0)return {};
    vector<vector<TreeNode *>> forest;
    forest.push_back({new TreeNode(0)});
    for (int i = 1; i < (n + 1)/2; i++)
    {
        vector<TreeNode *> ans;
        for (int j = 0; j < i; j++)
        {
            vector<TreeNode *> l = forest[j];
            vector<TreeNode *> r = forest[i - 1 - j];
            for (int k = 0; k < l.size(); k++)
            {
                for (int m = 0; m < r.size(); m++)
                {
                    ans.push_back(new TreeNode(0, l[k], r[m]));
                }
            }
        }
        forest.push_back(ans);
    }
    return forest[forest.size() - 1];
        
    }
};