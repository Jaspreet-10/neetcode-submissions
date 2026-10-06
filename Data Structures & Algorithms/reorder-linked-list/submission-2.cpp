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
    ListNode* findMiddleNode(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* node){
        ListNode* cur = node, *prev = NULL;
        while(cur!=NULL){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    void shuffleList(ListNode* head, ListNode* prev){
        ListNode* second = prev;
        ListNode* first = head; 
        while (second != NULL) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;  
            first->next = second;                 
            second->next = firstNext;
            first = firstNext;
            second = secondNext;
        }
        return ;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* middleNode = findMiddleNode(head);
        ListNode* second = middleNode->next;
        middleNode->next = NULL;
        ListNode* prev = reverseList(second);
        shuffleList(head, prev);   
        return ;
    }
};
