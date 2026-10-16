/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>m;
        Node* cur = head;
        Node* res = new Node(0), *temp = res;
        while(cur!=NULL){
            res->next = new Node(cur->val);
            m[cur] = res->next;
            res = res->next;
            cur = cur->next;
        }
        cur = head;
        res = temp->next;
        while(res!=NULL){
            res->random = m[cur->random];
            res = res->next;
            cur = cur->next;
        }
        return temp->next;
    }
};
