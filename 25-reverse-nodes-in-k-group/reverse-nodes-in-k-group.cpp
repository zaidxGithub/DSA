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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Step 1:count the current Node->
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL && cnt < k) {
            cnt++;
            temp = temp->next;
        }

        // Case2:Base on Count cnt==k then only revese is possible

        if (cnt == k) {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* forward = NULL;

            // Nodes equal to K are present there.

            // 1-> Revese those K Nodes
            int i = 0;

            while (i < k) {
                forward = curr->next;
                curr->next = prev;
                // update
                prev = curr;
                curr = forward;
                i++;
            }
            // 2-> Baki recursion karega
            ListNode* recKaHead = reverseKGroup(forward, k);

            // 3-> curr head and recurion ka head point karna h
            head->next = recKaHead;
            // retrurn head of the newNode ==prev hoga;
            return prev;

        } else {
            return head;
        }
    }
};