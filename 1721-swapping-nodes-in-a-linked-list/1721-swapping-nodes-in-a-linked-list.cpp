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
class Solution {   // TC:O(N) SC:O(N);
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp =  head;
        ListNode* temp2 = head;
        vector<int>arr;
        int count = 0; // for knowing the size of the vector
        while(temp!=NULL){  // copying the elements into the vector
            arr.push_back(temp->val);
            temp = temp->next;
            count++;
        }
        int i = 0;
        swap(arr[k-1],arr[count-k]);  // swapping the elements in the vector
        while(temp2!=NULL){  // again pushing the elements into the new linkelist
            temp2->val = arr[i++];
            temp2 = temp2->next;
        }
        
        return head;
    }
};