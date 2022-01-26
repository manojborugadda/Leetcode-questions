class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
      unordered_map<int,int> frequency;
        int good_pair=0;
        for(auto num : nums)
        {
            if(frequency.find(num) != frequency.end()){ // if we have already seen this element such that i<j
                good_pair+=frequency[num]; // add the number of time u have seen it 
            }
            
            frequency[num]++;
        }
        return good_pair;   
    }
};