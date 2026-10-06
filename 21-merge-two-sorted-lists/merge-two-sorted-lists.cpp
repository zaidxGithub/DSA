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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* newNode = new ListNode(-1000);
        ListNode* head = newNode;
        ListNode* temp3 = head;

        while (temp1 != NULL && temp2!= NULL) {

            // step1;
            if (temp1->val <= temp2->val) {
                // isolte the temp1 Node and add in the newList and move the
                // temp1
                // temp1->next = NULL;
                // add in the list
                temp3->next = temp1;
                // increment both
                temp1 = temp1->next;
               
                temp3 = temp3->next;

            } else {

                // grater than
                // isolte the temp2 Node and add in the newList and move the
                // temp2

                // temp2->next = NULL;
                temp3->next = temp2;
                temp2 = temp2->next;
                // frd2 = frd2->next;
                temp3 = temp3->next;
            }
        }

        // means one of the List are empty now
        if (temp1 != NULL) {
            temp3->next = temp1;
        }
        if (temp2 != NULL) {
            temp3->next = temp2;
        }

        return head->next;
    }
};