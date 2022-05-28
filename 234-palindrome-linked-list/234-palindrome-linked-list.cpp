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
class Solution {   ///time O(N)  and O(1) space
public:
    bool isPalindrome(ListNode* head) {
        
        // finding the MID in the LinkedList
        ListNode* slow = head , *fast = head , *mid = NULL;
        while(fast != NULL and fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        ///-------IMPORTANT Property in LinkedList
        
        // when we traverse all the elements in the using FAST and SLOW Pointers
        // if the FAST does not equals to NULL it means ODD number of elements are
        // present in the LinkedList otherwise EVEN  no.of elements are there
        
        if(fast !=NULL){  /// ODD no.of Elements
            mid = slow->next;
        }
        else{        /// EVEN no.of Elements
            mid = slow;
        }
        // so we got the MID of the LinkedList and now we have to REVERSE all the              elements after the RIGHT side of the MID(excluding)
        
        ListNode* prev = NULL , *temp = NULL;
        
        while(mid != NULL){
            temp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = temp;
        }
        
        // now "prev" becomes the HEAD of the REVERSED elements in the LinkedList
        while(prev != NULL){
            if(prev->val != head->val) return false;
            //else
            prev = prev->next;
            head = head->next;
        }
        
        return true;
    }
};