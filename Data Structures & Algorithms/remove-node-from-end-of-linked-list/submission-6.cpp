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
        int count = 0, k = 0;
        while(cur!=NULL){
            ++count;
            cur = cur->next;
        }
        if(count == n) return head->next;
        if(count == 0 or (count == 1 and n == 1)) return NULL;

        cur = head;
        while(k < count - n - 1){
            cur = cur->next;
            ++k;
        }
        cur->next = cur->next->next;
        return head;
    }
};
