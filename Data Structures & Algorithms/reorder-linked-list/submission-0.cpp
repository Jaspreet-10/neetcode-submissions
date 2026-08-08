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
    ListNode* findMidPoint(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;  // Find the last node of the first half.
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseMidList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;  // Reverse the linked list.
        while (cur != NULL) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;  // Find the middle of the list.
        ListNode* mid = findMidPoint(head);              // Store the beginning of the second half.
        ListNode* second = mid->next;                    // Split the list into two halves.
        mid->next = NULL;                                // Reverse the second half.
        second = reverseMidList(second);
        ListNode* first = head;  // Merge both halves alternately.
        while (second != NULL) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;  // Connect first node to second node.
            first->next = second;                 // Connect second node to next first node.
            second->next = firstNext;             // Move to the next nodes.
            first = firstNext;
            second = secondNext;
        }
    }
};
