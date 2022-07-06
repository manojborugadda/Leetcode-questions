class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
	    // max heap stores number and index
        priority_queue<pair<int, int>> maxpq;
		// min heap stores number and index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;   
        int res = 0;
        for(int start = 0, end = 0, len = (int)nums.size(); end < len; ++end){
            minpq.emplace(nums[end], end);
            maxpq.emplace(nums[end], end);
            while(start <= end && maxpq.top().first - minpq.top().first > limit){
				// if the difference between the top elements exceed the limit, 
				// we need to remove one of them until the invariant is satisfied.
                ++start;
				// remove elements from the heap that have  index less than start index.
                while(!maxpq.empty() && maxpq.top().second < start) maxpq.pop();
                while(!minpq.empty() && minpq.top().second < start) minpq.pop();
            }
			// update  result.
            res = max(res, end - start + 1);
        }
        return res;
    }
};