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
    ListNode *detectCycle(ListNode *head) {
        //maintain a trck of visisted Nodes
        //revisit == cycle statrt from theeir

        unordered_map<ListNode*,bool>visited;

        ListNode*temp=head;
        while(temp!=NULL){

            if(visited[temp]==true){
                return temp;
            }else{
                //mark it visited
                visited[temp]=true;
                temp=temp->next;
            }

        }

        //reaching here means no cycle deetcted above
        return NULL;
        
    }
};