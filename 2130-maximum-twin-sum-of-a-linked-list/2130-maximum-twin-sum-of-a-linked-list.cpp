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
class Solution {   // TC:O(N) SC:O(1)
public:
    int pairSum(ListNode* head) {
        
        ListNode* fast = head,*slow = head,*mid = NULL;
        //finding the MID in the linkedList
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast!=NULL){ // if the fast!=NULL length of LinkedList is ODD
            mid = slow->next;
        }else{ // fast==NULL then Length of LinkedList is EVEN
            mid = slow;
        }
         // so we got the MID of the LinkedList and now we have to REVERSE all the              elements after the RIGHT side of the MID(excluding)
       
        ListNode* prev = NULL , *nxt=NULL;
        
        while(mid!=NULL){
            nxt = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nxt;
        }
        
        int ans = 0; // maximum twin sum variable
        
        // now "prev" becomes the HEAD of the REVERSED elements in the LinkedList
    // now we add the head of actual Linkedlist and head of reversed elements i.e PREV
        // it has become like this 5-->4-->NULL 1-->2-->NULL
        // here HEAD is 5 and PREV is 1
        while(prev!=NULL){ 
           ans = max(ans,prev->val+head->val);
            prev = prev->next;
            head = head->next;
        }
        
        return ans;
    }
};