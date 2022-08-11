/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        while(!q.empty() and q.front())
        {
            int size=q.size();
            queue<Node*>k;
            for(int i=0;i<size;i++)
            {
                Node* d = q.front();
                q.pop();
                if(!q.empty())d->next=q.front();
                else d->next=NULL;
                if(d->left)k.push(d->left);
                if(d->right)k.push(d->right);
            }
            q=k;
        }
        return root;
    }
};