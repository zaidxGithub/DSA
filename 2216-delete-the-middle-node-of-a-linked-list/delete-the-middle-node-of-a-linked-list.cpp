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
  
    ListNode* deleteMiddle(ListNode* head) {
        //Base case for 1 Node
        //USING THE MODDIFIED TORTOISE AND HEAR ALGO TO REACH NODE BEFORE MIDDLE NODE



        if(head==NULL || head->next==NULL){
            return NULL;
        }

        ListNode*slow=head;
        ListNode*fast=head;

        //waiting slow for one step to rach Middle-1 th node
        fast=fast->next->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        //slow is at the middle -1 the node
        ListNode*middleNode=slow->next;


        slow->next=slow->next->next;
        //delete the middle Node

        middleNode->next=NULL;
        delete middleNode;


        return head;

    }
};