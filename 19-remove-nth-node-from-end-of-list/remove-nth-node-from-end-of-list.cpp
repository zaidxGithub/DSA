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
    ListNode* reverseLL(ListNode*& head) {

        // Base Case
        if (head == NULL)
            return head;

        ListNode* prev = NULL;

        ListNode* crr = head;
        while (crr != NULL) {
            ListNode* frd = crr->next;
            // break old and amke new links
            crr->next = prev;
            // increment all
            prev = crr;
            crr = frd;
        }

        head = prev;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == NULL)
            return head;
        if (head->next == NULL && n == 1)
            return NULL;

        // to delete n from alst

        // step1:revrse list
        head = reverseLL(head);
        // delete n from front

        // Case 2:
        if (n == 1) {
            // delete the head Node
            ListNode* crr = head;
            head = head->next;
            crr->next = NULL;
            delete crr;

        } else {
            // any other node middle or last

            // set the 3 pointers

            ListNode* prev = head;
            ListNode* crr = head;
            ListNode* frd = head;

            // MOVE n-2 steps to reach the nth-1 node
            for (int i = 1; i <= n - 2; i++) {
                prev = prev->next;
            }
            crr = prev->next;
            frd = crr->next;

            // re link
            prev->next = frd;
            crr->next = NULL;
            delete crr;
        }

        // reverse again
        head = reverseLL(head);
        // retunr head;
        return head;
    }
};