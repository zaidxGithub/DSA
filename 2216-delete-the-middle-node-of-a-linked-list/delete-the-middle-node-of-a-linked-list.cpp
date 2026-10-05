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
    int lengthOfLL(ListNode*& head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }
    ListNode* deleteMiddle(ListNode* head) {
        //Base case for 1 Node

        if(head->next==NULL){
            return NULL;
        }

        // Middle Node is the n/2 th Node
        // ll  based so MID node n/2+1 th Node
        // STep3:reach the n/2 Node by traverseing N-2 Nodes

        int n = lengthOfLL(head);
        int middleNode = (n / 2) + 1;

        // traverse (n/2+1)-2  times to rach n/2th Node..
        int travserseLength = ((n / 2) + 1) - 2;
        ListNode* prev = head;

        for (int i = 1; i <= travserseLength; i++) {
            prev = prev->next;
        }
        ListNode* crr = prev->next;

        ListNode* frd = crr->next;

        // set pointers

        // delete Node.

        prev->next = frd;
        crr->next = NULL;
        delete crr;

        return head;
    }
};