class Solution {  //TC:O(N)  SC:O(N)
public:
    int countSubarrays(vector<int>& nums, int k) {
        int ans = helper(nums.size(),nums,k);
        return ans;
    }
    
    int helper(int n , vector<int>&arr,int t) {
        map<int,int>mp;
        int sum = 0;
        long long count = 0;
        bool flag = false;
        mp[0] = 1;
        for(int i = 0;i<n;i++) {
            if(arr[i] < t) { 
                sum--;
            }
            if(arr[i] > t) {
                sum++;
            }
            if(arr[i] == t) { //t is found
                flag = true;
            }
            
            if(flag) { //count incrementing 
                /*
                mp[sum] is to count the odd-length subarrays,
                mp[sum - 1] is to count the even length subarrays
                */
                count += mp[sum] + mp[sum-1];
            }else {
                mp[sum]++;
            }
        }
        return count;
    }
};