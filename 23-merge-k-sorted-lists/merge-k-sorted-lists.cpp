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
    // ListNode* mergeKLists(vector<ListNode*>& lists) {

    //     //Brute force approach

    //     //make array of the LLS
    //     vector<int>arr;
    //     for(auto it:lists){
    //         //it is each LL
    //         ListNode*temp=it;
    //        while(temp!=NULL){
    //         arr.push_back(temp->val);
    //         temp=temp->next;
    //        }
    //     }
    //     //sort the arrya
    //     sort(arr.begin(),arr.end());
    //     //make LL from sorted arrayt and return;
    //     ListNode*dummy=new ListNode(-1);
    //     ListNode*head=dummy;

    //     for(int i=0;i<arr.size();i++){
    //         ListNode*newNode=new ListNode(arr[i]);

    //         dummy->next=newNode;
    //         dummy=dummy->next;

    //     }
    //     return head->next;
    // }

    ListNode* mergeTwoSortedLists(ListNode*& list1, ListNode*& list2) {

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        // make the l1 smaller one
        if (l1->val > l2->val)
            swap(l1, l2);
    ListNode*smallerHead=l1;

        while (l1 != NULL && l2 != NULL) {

            ListNode* temp = NULL;
            while (l1 != NULL && l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1, l2);
        }

        return smallerHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // base case for nullpointer
        if (lists.size() == 0)
            return NULL;

        if (lists.size() < 2)
            return lists[0];
        ListNode* head1 = lists[0];
        ListNode* head2 = lists[1];

        head1 = mergeTwoSortedLists(head1, head2);

        for (int i = 2; i < lists.size(); i++) {

            head1 = mergeTwoSortedLists(head1, lists[i]);
        }

        return head1;
    }
};