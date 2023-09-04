class Solution {//TC:O(N)   SC:O(1) as in hash, we are storing indexes of 0 and 5 only.
public:
    int minimumOperations(string nums) {
        unordered_map<char,int>map;
        int ans = -1;
        int count = 0;
        int n = nums.length();
        for(int i = n;i>=0;i--) {       //Traverse from last character.
            //For 2 and 7 check for 5 
            if(nums[i]=='2' or nums[i]=='7') {
                if(map.count('5')) {
                    ans = map['5'] - i - 1 + n - 1 - map['5'];
                    break;
                }
                //for 5 and 0 check for 0
            }else if(nums[i] == '5' or nums[i] == '0') {
                if(map.count('0')) {
                    ans = map['0'] - i - 1 + n - 1 - map['0'];
                    break;
                }
            }
            map[nums[i]] = i; //if it traversing for the first time we add to the map
            if(nums[i] == '0') count++; // for the test case '10' 
        }
        if(ans == -1) return n - count;
        return ans;
    }
};
