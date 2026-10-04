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
    ListNode* oddEvenList(ListNode* head) {

        // Base cse
        if (head == NULL || head->next == NULL)
            return head;

        // Step 1:set odd and even And evenHead pointers
        ListNode* even = head->next;
        ListNode* odd = head;
        ListNode*evenHead=head->next;

        // step2: reLink the odd to od index nodes
        while (even != NULL && even->next != NULL) {
            // step3:relink the even to even index nodes and

           
            odd->next = odd->next->next;
             even->next = even->next->next;

            // step 4:Move 2 steps

           
            odd = odd->next;
             even = even->next;
        }

        // Link the odd to the even List
        odd->next = evenHead;
        return head;
    }
};