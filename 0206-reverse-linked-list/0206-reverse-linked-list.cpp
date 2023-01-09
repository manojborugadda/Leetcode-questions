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
class Solution {  //TC:O(N) SC:O(1)
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *cur = head, *nex;
        
        while(cur != NULL){
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        
        return pre;
    }
}; 
