https://leetcode.com/problems/sort-array-by-increasing-frequency/solutions/1146525/c-solution-using-maps/comments/2533894

```
https://leetcode.com/problems/sort-array-by-increasing-frequency/discuss/1474205/c%2B%2B-oror-Sort-Array-by-Increasing-Frequency

Superb explanation using MAX HEAP 

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : mp){
            pq.push({-it.second,it.first});
        }
        vector<int> result;
        while(!pq.empty()){
            int x = pq.top().first;
            for(int i=0;i<abs(x);i++){
                result.push_back(pq.top().second);
            }
            pq.pop();
        }
        return result;
    }
};
```
