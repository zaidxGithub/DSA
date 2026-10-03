/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        //  FLOYDES CYCLE ALGO
        ListNode* slow = head;
        ListNode* fast = head;
        // step 1: find the cycle

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // step2: reset the fast to the head
                fast = head;
                // step3:find the cycle again and return the meeting Node
                while (fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        //reaching here means no Cycle is there...
        return NULL;
    }
};