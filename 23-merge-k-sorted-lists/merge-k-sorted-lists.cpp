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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //Brute force approach 

        //make array of the LLS
        vector<int>arr;
        for(auto it:lists){
            //it is each LL
            ListNode*temp=it;
           while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
           }
        }
        //sort the arrya
        sort(arr.begin(),arr.end());
        //make LL from sorted arrayt and return;
        ListNode*dummy=new ListNode(-1);
        ListNode*head=dummy;


        for(int i=0;i<arr.size();i++){
            ListNode*newNode=new ListNode(arr[i]);
            
            dummy->next=newNode;
            dummy=dummy->next;
          

        }
        return head->next;
    }
};