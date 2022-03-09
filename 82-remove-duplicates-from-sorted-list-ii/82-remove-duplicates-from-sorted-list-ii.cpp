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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head== NULL or head->next== NULL){
                return head;
        }
        ListNode* dummy = new ListNode(0,head);
        ListNode *temp = dummy; 
        ListNode* ptr = head;
        while(ptr)
        {
             if(ptr->next != NULL and ptr->val == ptr->next->val)
             {
                 while(ptr->next != NULL and ptr->val == ptr->next->val)
                 {
                     ptr = ptr->next;
                 }
                 
                 temp->next = ptr->next;
            }
            else
            {
                 temp = temp->next;
            }
            ptr = ptr->next;
         }
            return dummy->next;
    }
};