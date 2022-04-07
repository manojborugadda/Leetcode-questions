class Solution {
public:
    int halveArray(vector<int>& nums) {
        int count = 0;
        double sum = 0;
        priority_queue<double>pq;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
            sum  =sum+nums[i];
        }
        double target = sum/2;
        
        while(sum>target){ // if the sum of the whole vector is greater than its half sum
            count++;
            double highest  = pq.top();
            pq.pop();
            sum = sum-highest;
            highest = highest/2;
            sum = sum+highest;
            pq.push(highest);
            
        }
        
        return count;
    }
};