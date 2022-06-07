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
class Solution { // TC:O(N)  SC:O(1)
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head== NULL or head->next==NULL or head->next->next==NULL) return head;
        ListNode* odd = head ;
        ListNode* even = head->next;
        ListNode* even_head = even; // pointer points to head of even
        
        while(odd->next !=NULL and even->next!=NULL){
            odd->next = even->next;
            even->next = odd->next->next;
            odd = odd->next; // updating the odd
            even = even->next; // updating the even
        }
        
        odd->next = even_head; // connecting oddpointer tail to the head of even pointer
        return head; // returning head
    }
};