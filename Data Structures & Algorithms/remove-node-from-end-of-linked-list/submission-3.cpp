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
        ListNode* cur = head;
        int count = 0;
        while(cur!=NULL){
            ++count;
            cur = cur->next;
        }
        cur = head;
        int k = count - n;
        if(k == 0) return head->next;
        while(k>1){
            cur = cur->next;
            --k;       
        }
        cur->next = cur->next->next;
        return head;
    }
};
