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
class Solution {//TC:O(N)  SC:O(1)
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>temp;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        int i = 1;//for calculating the indexes
        while(curr and curr->next) {
            if((curr->val > next->val and curr->val > prev->val ) or (curr->val < next->val and curr->val < prev->val)) {
                temp.push_back(i);
            }
            prev = prev->next;
            curr = curr->next;
            next = next->next;
            i++; //indices for knowing the values of Indexes so that we can calculate
        }
        int n = temp.size();
        if(temp.size() < 2) return {-1,-1};
        int maxDistance = temp[n-1] - temp[0]; //maximum distance between two distinct local min or max
        int minDistance  = INT_MAX;
        for(int i= 1;i<n;i++) {//minimum distance between two distinct local min or max
            minDistance = min(temp[i] - temp[i-1] , minDistance);
        }
        return {minDistance , maxDistance};
    }
};
