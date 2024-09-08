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
class Solution {////TC:O(N)  SC:O(1)
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //calculating the length of the linkedlist
        int len = 0;
        ListNode* current = head;
        while(current != NULL) {
            len++;
            current = current->next;
        }

        //determining the size of each sub linked list
        int listSize = len/k;
        int extra = len%k;

        //initialising the answer vector
        vector<ListNode*>ans(k,nullptr);
        current = head;//keeping the current pointer to head

        //splitting the linkedlist into K parts
        for(int i = 0;i<k;i++) {
            int sublistSize = ( i < extra) ? (listSize + 1) : listSize;
            if (sublistSize == 0) {
                ans[i] = nullptr;
            } else {
            ListNode* subListHead = current;
            for(int j = 0;j < sublistSize-1;j++) {
                current = current->next;
            }
            ListNode* nextNode = current->next;
            current->next = nullptr;
            ans[i] = subListHead;
            current = nextNode;
        }
    }
        return ans;
    }
};

/***
    size = length // k
    extra = length % k
**/
