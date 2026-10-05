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

int getLen(ListNode*head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;

    }
    return cnt;
};
    ListNode* rotateRight(ListNode* head, int k) {

        // Base case
        if(head==NULL)return head;
        int len=getLen(head);

        int actRotateK=k%len;
        if(actRotateK==0) return head;

        //step get the last new Node Pos
        int newLastNodePos=len-actRotateK-1;
        ListNode*newlastNode=head;

        for(int i=1;i<=newLastNodePos;i++){
            newlastNode=newlastNode->next;

        }
        //newLastNode is set now make newHead
        ListNode*newHead=newlastNode->next;
        //delete old link of newLastNode
        newlastNode->next=NULL;

        //link the lastNode to the Head

        ListNode*temp=newHead;
        while(temp->next!=NULL){
            temp=temp->next;

        }
        temp->next=head;
        return newHead;


    }
};