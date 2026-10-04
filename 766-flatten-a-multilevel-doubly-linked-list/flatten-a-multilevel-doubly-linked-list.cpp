/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head) {

        if (!head)
            return NULL;
        Node* temp = head;
        Node* tail = temp;
        while (temp) {

            if (temp->child) {

                Node* tail = solve(temp->child);
                Node* frd = temp->next;
                // add this tail int curr LL
                temp->next = temp->child;
                temp->next->prev = temp;

                tail->next = frd;
                if (frd) {
                    frd->prev = tail;
                    
                }
                temp->child = NULL;

                // tail
            }
            // uodate the tail
            tail = temp;
            temp = temp->next;
        }

        return tail;
    }
    Node* flatten(Node* head) { 
    solve(head);
    return head; }
};