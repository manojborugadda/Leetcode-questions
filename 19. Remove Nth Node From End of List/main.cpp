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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int nodesCount = 0;
        while(curr!= NULL) {//calculating total no of NODES in the LinkedList
            curr = curr->next;
            nodesCount++;
        }
        if(nodesCount - n == 0) {//if the no of nodes in the linkedList and Nth node from last is same
            head = head->next;
            return head;
        }

        int travel = nodesCount - n - 1; // calculating for having previous Node to Nth node from Last
        curr = head; // assinging the "curr" node to head again as we went to the last Node for calculating total no of nodes in the linkedList
        while(travel--) {
            curr = curr->next;
        }

        curr->next = curr->next->next; // assigning the curr node next to next of it . so that our ask will be satisfied
        return head;

    }
};
