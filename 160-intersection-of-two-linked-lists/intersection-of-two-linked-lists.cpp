/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        unordered_map<ListNode*, bool> visited;

        ListNode* temp = headA;

        while (temp != NULL) {
            // travserse and mark the enrtry of each Node is truel
            visited[temp] = true;
            temp = temp->next;
        }

        temp=headB;
        while(temp!=NULL){
            if(visited[temp]==true){
                //alreday visited in first travseral of Node A .this is intrsection point'
                return temp;
            }
            visited[temp]=true;
            temp=temp->next;
        }

        return NULL;
    }
};