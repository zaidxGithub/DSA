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
    void traverseLL(ListNode*& head, vector<int>& arr) {
        ListNode* temp = head;

        while (temp != nullptr) {
            int data = temp->val;
            arr.push_back(data);
            temp = temp->next;
        }
    };

    int getDecimalValue(ListNode* head) {

        vector<int> arr;
        traverseLL(head, arr);
        int p = 0;
        int number = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            number += arr[i] * pow(2, p);
            p++;
        }

        return number;
    }
};