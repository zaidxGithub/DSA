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
    int getLenLL(ListNode*& head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    };
    ListNode* getMiddleNodeLL(ListNode*& head) {

        if (head == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    };
    ListNode* reverseLL(ListNode*& head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while (curr != NULL) {
            forward = curr->next;
            // Change the ppointer
            curr->next = prev;
            // update the locatoins of pointers
            prev = curr;
            curr = forward;
        }

        head = prev;
        return head;
    }

    bool isPalindrome(ListNode* head) {
        int len = getLenLL(head);
        // calculating mid noe
        ListNode* mid = getMiddleNodeLL(head);
        cout << "middle NodeL: " << mid->val << endl;
        // Case:even or odd-> based we set the middle Node

        if (len & 1) {
            // Len is odd
            mid = mid->next;
        }
        // Reverse from mid:
        mid = reverseLL(mid);

        // two LL are there not One with staring->head and second starting Mid
        // Compare
        ListNode* temp = head;
        while (temp != NULL && mid != NULL) {

            if (temp->val != mid->val) {
                return false;
            }
            temp = temp->next;
            mid = mid->next;
        }
        // reaching here means all data was same
        return true;
    }
};