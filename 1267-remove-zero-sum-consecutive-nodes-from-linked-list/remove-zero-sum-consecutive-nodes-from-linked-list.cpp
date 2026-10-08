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
    ListNode* removeZeroSumSublists(ListNode* head) {


        //step create a dummyNode and attach in front of head
        ListNode*dummy=new ListNode(0);
        dummy->next=head;

        //map to store the prefixSum,Node

        unordered_map<int,ListNode*>prefixSumMap={ {0,dummy}};
        //default store the 0 sum with dummy Node
       
        //usePrefix sum to calculate and store in the map is not already

        int prefixSum=0;

        //start the loop 
        ListNode*ptr=head;

        while(ptr!=NULL){
            prefixSum+=ptr->val;

            if(prefixSumMap.find(prefixSum)!=prefixSumMap.end()){
                //prefix Sum already in the map-->> meaans all the sum of nodes between the prefixSum Node and current Node ptr is ==0

                //1Step:take the Node where the sum was same before

                ListNode*prev=prefixSumMap[prefixSum];
                ListNode*temp=prev->next;
                int tempSum=prefixSum;

                //move temp and delete all the nodes between prev and ptr by using the tempSum
                while(temp!=ptr ){

                    //calcaute the sumTillCurrNode
                    tempSum+=temp->val;
                    prefixSumMap.erase(tempSum);
                    temp=temp->next;
                }

                //after deleting the nodes
                // relink the prev and ptr

                prev->next=ptr->next;

            }else{
                //add the sum in the map
                prefixSumMap[prefixSum]=ptr;
            }



            ptr=ptr->next;
        }
        return dummy->next;
        
    }
};