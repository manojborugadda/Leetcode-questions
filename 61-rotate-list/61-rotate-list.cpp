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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;//edge case
        int len=1;
        ListNode* curr=head;
        while(curr->next){//counting length of ll
            len++;
            curr=curr->next;
        }
        curr->next=head;//connecting the last node to the head(makingcircular linked list) 
        k=k%len;//
        k=len-k;
        while(k--)curr=curr->next;//travers to the (len-k) th node
        head=curr->next;//move the head to the new head
        curr->next=NULL;//break the list 
        return head;
    }
};