class Solution { //Time complexity: O(n)
                 //Space complexity: O(n)
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
        int longest_sequence = 0;
        int j;
        for(auto x:nums){
            
            if(set.count(x)==0){
                continue;
            }
            
            int prev = x-1 , next = x+1;
            
            while(set.find(prev)!=set.end()){
                prev--;
            }
            
            while(set.find(next)!=set.end()){
                next++;
            }
            
            longest_sequence = max(longest_sequence , next-prev-1);
            set.erase(x);
        }
        return longest_sequence;
    }
};

/*
Insert all the elements of the array into set.
Check if the previous number (nums[i] - 1) is present in the set, if it is then that number (nums[i]) is not the starting of the sequence.
If previous number is not present, that means that number is the starting of the sequence.
Make a count variable to count the length of the sequence and current variable to store the current number.
Now in a while loop, traverse and keep searching for consecutive elements until the condition is false.
Now store the maximum of longest_sequence and current length of the sequence.

*/