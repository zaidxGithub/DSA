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
    ListNode* middleNode(ListNode* head) {
         if(head==NULL){
            return head;
        }

        // SLOW AND FAST POINTERS

        // SLOW- MOVES 1 STEP
        // FAST-MOVES 2X OF SLOW
        ListNode* slow = head;
        ListNode* fast = head;
       

        while (fast != NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is pointing to the middle Node

        return slow;
    }
};