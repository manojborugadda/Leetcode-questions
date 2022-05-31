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


// TC:O(N)---- as we are doing in one pass 
//SC:O(1)--------as we using only 3 pointers
class Solution { 
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(-1); 
        dummy->next =  head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        while(n >= 0){ // iterating untill 'n' Nodes are there between first and dummy pointer
            first = first->next;
            n--;
        }
        
        while(first!=NULL){  // moving both first and second pointers
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;// pointing the next of second to next of next of second
        return dummy->next; 
        
    }
};