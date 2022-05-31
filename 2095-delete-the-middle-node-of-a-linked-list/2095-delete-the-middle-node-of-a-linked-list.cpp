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
        
        if(head->next == NULL) return NULL; // if there is only one element in the Linkedlist
        
      ListNode* fast = head , *slow = head , *prev_of_slow = head;
        
        while(fast!=NULL and fast->next!=NULL){
            prev_of_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev_of_slow->next = slow->next;  /// pointing the prev of slow to next of slow pointer
        
        return head;  /// returning the head
        
        
        
        
        
        
        
    }
};