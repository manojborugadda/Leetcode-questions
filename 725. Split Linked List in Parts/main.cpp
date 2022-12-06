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
class Solution { //TC:O(N)  SC:O(1)
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        int N  = totalCount(head);
        int numNodes = N/k;
        int extraNodes = N % k;
        ListNode* temp = head;
        while(temp) {
            ans.push_back(temp);
            int currLen = 1;
            while(currLen < numNodes) {
                currLen++;
                temp = temp->next;
            }
            //if the extra nodes are there we add them according to the chunks we divided
            if(extraNodes > 0 and N > k) {
                temp = temp->next;
                extraNodes--;
            }
            //splitting the first linkedlist by keeping NULL at the END of the list
            ListNode* nextHead = temp->next;
            temp->next = NULL;
            temp = nextHead;
        }
        while(N < k) {
            ans.push_back(NULL);
            N++;
        }
        return ans;
    }

    int totalCount(ListNode* root) {
        int n = 0;
        while(root) {
            n++;
            root = root->next;
        }
        return n;
    }
};
