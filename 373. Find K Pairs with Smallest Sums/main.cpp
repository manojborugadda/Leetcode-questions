typedef pair<int,pair<int,int>>P;
class Solution {//TC:O(M*N*logK)  SC:O(K)
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        if(nums1.size()== 0 or nums2.size() == 0 or k <= 0 ) {
            return ans;
        }
        priority_queue<P>pq; //max heap
        for(int i = 0;i<nums1.size();i++) {
            for(int j =0;j<nums2.size();j++) {
              int sum  = nums1[i] + nums2[j];
              if(pq.size() < k) {
                  pq.push(make_pair(sum, make_pair(i,j)) );
               } else if(pq.top().first > sum) {//If the priority queue is already full, the we removes the tuple with the largest sum and adds the new tuple to the priority queue.
                    pq.pop();
                    pq.push(make_pair(sum, make_pair(i,j)));
                 }else {
                    break;
                } 
            }
        }

        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            ans.push_back({nums1[i],nums2[j]});
        }

        return ans;
    }
};
