class Solution {//TC:O(nlogn)  SC:O(N)
public:
    int minimumDeviation(vector<int>& nums) {
        if(nums.empty()) return INT_MAX;
        priority_queue<int>pq;
        int mini = INT_MAX;//minimum element
        for(auto num : nums) {
            if(num % 2 == 0) {
                pq.push(num);
                mini = min(mini,num);
            }else {
                pq.push(num * 2);
                mini = min(mini,num*2);
            }
        }

        int ans = INT_MAX;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            ans = min(ans,top-mini);
            if(top%2!=0){
                break;
            }
            mini = min(mini,top/2);
            pq.push(top/2);
        }
        return ans;
    }
};
