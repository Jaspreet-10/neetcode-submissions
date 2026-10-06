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
        ListNode* temp = head, *res = head;
        if(head == NULL) return NULL;
        int count = 0;
        while(temp!=NULL){
            ++count;
            temp = temp->next;
        }

        if(count == 1 && n == 1) return NULL;
        if(count == n) return head->next;
        
        int k = 1;
        while(k<count-n){
            ++k;
            head = head->next;
        }
        head->next = head->next->next;
        return res;
    }
};
