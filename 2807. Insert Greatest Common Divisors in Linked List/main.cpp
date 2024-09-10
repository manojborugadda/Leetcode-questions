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
class Solution {//tc:o(n)  sc:o(1)
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    } 

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode*dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* a = head;
        ListNode* b = head->next;
        while( a != NULL and b != NULL ) {
            int val = gcd(a->val , b->val);
            ListNode* newNode = new ListNode(val);
            a->next = newNode;
            newNode->next = b;
            a = b;
            b = b->next;
        }
        return dummy->next;
    }
};
