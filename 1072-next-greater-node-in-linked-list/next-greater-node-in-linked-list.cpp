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

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* frd = NULL;

        while (curr!=NULL ) {
            frd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frd;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* newHead = reverseLL(head);

        stack<int> st;
        st.push(0);
        // take this newHead as newLL and find the prev grater Nodes
        vector<int> ans;
        while (newHead != NULL) {
            int ele = newHead->val;
            while (!st.empty() && st.top() != 0 && st.top() <= ele) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(ele);

            newHead = newHead->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};