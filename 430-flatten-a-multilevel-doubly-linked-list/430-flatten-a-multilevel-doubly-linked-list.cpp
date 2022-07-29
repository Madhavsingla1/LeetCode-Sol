/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* a =head;
        while(a)
        {
            if(a->child)
            {
                Node* b= a->next;
                a->next=a->child;
                a->next->prev=a;
                Node* c=a;
                while(c->next)
                    c=c->next;
                c->next=b;
                if(b)b->prev=c;
                a->child=NULL;
            }
            a=a->next;
        }
        return head;
    }
};