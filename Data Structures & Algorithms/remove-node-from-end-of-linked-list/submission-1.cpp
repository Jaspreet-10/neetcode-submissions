/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            ++count;
            temp = temp->next;
        }
        if(n == count) return head->next;
        int i = 1;
        temp = head;
        while(i<count - n){
            ++i;
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        if(temp->next!=NULL)
        temp->next = temp->next->next;
        return head;
    }
};
