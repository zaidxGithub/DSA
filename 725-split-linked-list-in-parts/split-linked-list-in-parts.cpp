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

    int getLen(ListNode*& head) {
        int cnt = 0;

        ListNode* temp = head;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int len = getLen(head);

        int eachPartLen = len / k;
        int firstNParts = len % k;

        vector<ListNode*> ans;

        ListNode* curr = head;

        for (int i = 0; i < k; i++) {

            // First 'len % k' parts get one extra node
            int partSize = eachPartLen;

            if (i < firstNParts) {
                partSize++;
            }

            // Empty part
            if (partSize == 0) {
                ans.push_back(NULL);
                continue;
            }

            // This is the head of current part
            ListNode* partHead = curr;

            // Move to last node of current part
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            // Save next part's starting node
            ListNode* nextPart = curr->next;

            // Break current part
            curr->next = NULL;

            // Add current part
            ans.push_back(partHead);

            // Move to next part
            curr = nextPart;
        }

        return ans;
    }
};