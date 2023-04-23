class Solution {//TC:O(nlogn) SC:O(N)
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        map<int,int>map;
        for(int i = 0;i<k-1;i++) {//maintaining the MAP for first 3 numbers
            map[nums[i]]++;
        }
        //we insert number into the MAP taking from beginning(right side) of the vector and DELETE the number from ENDING(left) of the vector
        for(int i = k-1;i<nums.size();i++) {//here SLIDING WINDOW hashmap takes place
            map[nums[i]]++;
            int total = 0;
            int number;
            for(auto y : map) {
                total += y.second;
                number = y.first;
                if(total >= x) {
                    break;
                }
            }

            if(map[nums[i-k+1]] == 1) {//if the number wehich is going to be DELETED from back of the vector's frequency is 1 we will delete that
                map.erase(nums[i-k+1]);
            }else {
                map[nums[i-k+1]]--;
            }

            ans.push_back(min(0,number));//if negative key is there we take otherwise we take ZERO if it is POSITIVE
        }
        return ans;   
    }
};
