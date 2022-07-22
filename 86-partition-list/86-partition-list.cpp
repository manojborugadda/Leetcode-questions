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
class Solution {  //TC :O(N)   SC:O(1)
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1); //dummy node for small
        ListNode* greater = new ListNode(-1);// dummy node for Greater
        
        ListNode* smallHead  = small; // smaller pointer
        ListNode* greaterHead  = greater;  // greater pointer
        
      //  nodes less than x come before nodes greater than or equal to x.
        ListNode* it = head;
        while(it != NULL){
            if(it->val < x){ //for elements smaller than x
                smallHead->next  = it;
                it = it->next;
                smallHead = smallHead->next;
            }
            else{ // for greater OR equal to the x value
                greaterHead->next  = it;
                it = it->next;
                greaterHead = greaterHead->next;
            }
        }
        
        // attaching the NULL to the last of the gPoint
        // connecting the last node of sPoint to the gPoint
        smallHead->next = greater->next;
        greaterHead->next =  NULL;
        
        return small->next;
    }
};