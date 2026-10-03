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
    ListNode* deleteDuplicates(ListNode* head) {

        //Base case
        //empty list || single Nopde

        if(head==NULL || head->next==NULL) return head;

        ListNode* prev = head;
        ListNode* curr = prev->next;

        // 2 pointers prev and Curr to keep track and compare.

        while (curr != NULL) {
            // step 1: if prev and curr are not same

            if (curr->val != prev->val) {
                prev = prev->next;
                curr = curr->next;
            } else {

                // step2: prev and curr are same

                // delete curr node
                // repoint the curr pointer to new Node

                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                curr = prev->next;
            }
        }

        return head;
    }
};