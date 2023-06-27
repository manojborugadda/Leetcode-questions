https://leetcode.com/problems/find-k-pairs-with-smallest-sums/solutions/3689975/c-easy-solution-max-heap-priority-queue/

```
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum = nums1[i] + nums2[j];
                
                if(pq.size() == k){
                    if(sum >= pq.top().first) break;
                    else{
                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                    }
                }
                else pq.push({sum,{nums1[i],nums2[j]}});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};
```
