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
        Node* temp = new Node(0), *res = temp, *cur = head;
        while(cur!=NULL){
            temp->next = new Node(cur->val);
            m[cur] = temp->next;
            temp = temp->next;
            cur = cur->next;
        }
        temp = res->next;
        cur = head;
        while(temp!=NULL){
            temp->random = m[cur->random];
            temp = temp->next;
            cur = cur->next;
        }
        return res->next;
    }
};
