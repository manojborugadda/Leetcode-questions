class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // here are taking the cumulative sum remainders  and storing in the MAP 
        // if the remainder is already existed in the MAP we increase the count else we add that remainder frequency in the MAP
        
        int n = nums.size();
        int count = 0 , sum = 0;
        unordered_map<int,int>mp;
        mp[0] = 1; // we assume the frequency of "0" as 1 and it is special case
        if(n<1) return 0;
        for(int i=0;i<n;i++){
            sum = sum+nums[i];
            int remainder = sum%k;
            if(remainder < 0) {    // if the remainder is less than 0 we have to add
                remainder += k ;
            }
            if(mp.find(remainder)!=mp.end()){
                count = count + mp[remainder];
            }
            mp[remainder]++; // increasing the frequency of that remainder
        }
    return count;
    }
};