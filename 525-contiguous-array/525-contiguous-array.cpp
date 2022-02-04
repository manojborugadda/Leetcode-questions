class Solution {
public:
    int findMaxLength(vector<int>& nums){ 
        unordered_map<int,int> mymap;
        int sum = 0;
        int longest_subarray = 0;
        
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i]==0?-1:1;       // we add '1' if element is ONE and add '-1' if the element if ZERO
            
            if(sum==0)
            {
                if(longest_subarray < i+1)
                    longest_subarray = i+1;
            }
            else if(mymap.find(sum)!=mymap.end())
            {
                if(longest_subarray < i-mymap[sum])
                    longest_subarray = i-mymap[sum];
            }
            else
                mymap[sum] = i;
        }
        
        return longest_subarray;
    }
    
    
    
    
  //  https://www.youtube.com/watch?v=9ZyLjjk536U
    
};